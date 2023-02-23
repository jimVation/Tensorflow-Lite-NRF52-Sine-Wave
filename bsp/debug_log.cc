/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "tensorflow/lite/micro/debug_log.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"

#define BUFFER_SIZE 50

// a static buffer to hold the output string for the non blocking NRF log function
char output_buffer[BUFFER_SIZE] = {0};

void DebugLog(const char* log_msg) 
{
    uint8_t copy_index = 0;

    // leave a space at end for null terminator
    while ((copy_index < (BUFFER_SIZE - 1)) && (log_msg[copy_index] != 0))
    {
        output_buffer[copy_index] = log_msg[copy_index];
        copy_index++;
    }

    output_buffer[copy_index] = 0;  // Make sure string has a null terminator

    NRF_LOG_INFO("%s", output_buffer);    
    NRF_LOG_FLUSH();
}
