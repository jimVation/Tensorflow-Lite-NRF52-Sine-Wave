#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/system_setup.h"
#include "tensorflow/lite/micro/micro_log.h"
#include "tensorflow/lite/micro/all_ops_resolver.h"

#include "TFLite_Top.h"
#include "sine_wave_model_data.h"

const tflite::Model* model = nullptr;
tflite::MicroInterpreter* interpreter = nullptr;
TfLiteTensor* input = nullptr;
TfLiteTensor* output = nullptr;
int inference_count = 0;

constexpr int kTensorArenaSize = 2056;
alignas(16) uint8_t tensor_arena[kTensorArenaSize];

void setup_tf_system(void)
{
   tflite::InitializeTarget(); 

  // Map the model into a usable data structure. This doesn't involve any
  // copying or parsing, it's a very lightweight operation.
  model = tflite::GetModel(g_sine_wave_data);

  if (model->version() != TFLITE_SCHEMA_VERSION) 
  {
    MicroPrintf("Model provided is schema version %d not equal to supported version %d.",
        model->version(), TFLITE_SCHEMA_VERSION);
    return;
  }

  // This pulls in all the operation implementations we need.
  // NOLINTNEXTLINE(runtime-global-variables)
  static tflite::AllOpsResolver resolver;

}
