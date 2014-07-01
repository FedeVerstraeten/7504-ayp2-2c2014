#ifndef COMMON_HPP
#define COMMON_HPP

#define KEY_NAME 0
#define KEY_ELEMENT 1
#define KEY_CONNECTION 2
#define PROGRAM_SHUT 1
#define EXIT_SUCCESS 0
#define ERROR_PROCESS -1
#define DEFAULT_THRESHOLD 5

using namespace std;

//Revisar cuales de los estados ya no son utiles.

typedef enum {
                OK,
                FAULT_POLLING,
                FAULT_MANUAL,
				FAULT_INFERENCE,
				FAULT_INFERENCE_MANUAL

                }statusHFC_t;


typedef enum {
                OKK,
                OK_INPUT,
                OK_INPUT_CIN,
                OK_INPUT_CIN_PROCESSING,
                OK_NETNAME,
                OK_OUTPUT,
                OK_OUTPUT_COUT,
                OK_ROUTE_NAME,
                OK_NETWORK_NAME,
                OK_NETWORK_ELEMENT,
                OK_NETWORK_TYPE,
                OK_CONNECTION,
                OK_NETWORK_NAMES,
                ERROR,
                ERROR_NETWORK_TYPE_UNKNOWN,
                ERROR_CONNECTION,
                ERROR_PROCESS_LINE,
                ERROR_NULL_POINTER,
                ERROR_MEMORY_NO_AVAILABLE,
                ERROR_TEXT_LINE_INVALID,
                ERROR_ARG,
                ERROR_NETNAME,
                ERROR_NO_ARGS,
                ERROR_INVALID_ARGUMENT,
                ERROR_STREAM_OUT,
                ERROR_NULL_FILE

                }status_t;

#endif
