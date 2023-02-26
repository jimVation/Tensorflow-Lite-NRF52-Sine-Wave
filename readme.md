Tensorflow Lite sine wave example implemented on Nordic nRF52840DK (PCA10056).

Project is built on the Nordic BSP example.

Nordic SDK: 17.0.2

Segger SES: 7.10a

Tensorflow Lite Library: Commit 3e6bf5ba, February 20, 2023 01:21 PM

Nordic SDK and TF Lite library not included in this repo.

Modify paths in project settings (Preprocessor -> User Include Directories) to match your installs of SDK and TF Lite.

Required Modification in TF Lite Library:
In common.h (in \tflite-micro\tensorflow\lite\kernels\internal), comment out lines 353 to 356 and 363, to get past error where it is looking for a built in function that does not seem to be present in the compiler.

Note: The TF Lite file micro_log.cc is replaced with a local version, to implement Nordic logging.

Segger RTT is enabled for logging.

Size: 426KB Flash, 30KB RAM
