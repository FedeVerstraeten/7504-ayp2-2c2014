#ifndef COMMON_HPP
#define COMMON_HPP
using namespace std;
typedef enum{
                OK,
                OK_INPUT,
                OK_INPUT_CIN,
                OK_INPUT_CIN_PROCESSING,
                OK_OUTPUT,
                OK_OUTPUT_COUT,
                OK_ROUTE_NAME,
                ERROR_NULL_POINTER,
                ERROR_MEMORY_NO_AVAILABLE,
                ERROR_TEXT_LINE_INVALID,
                ERROR_ARG,
                ERROR_ROUTE_NAME_INVALID,
                ERROR_NO_ARGS,
                ERROR_INVALID_INPUT_ROUTE,
                ERROR_INVALID_OUTPUT_ROUTE,
                ERROR_INVALID_ARGUMENT,
                ERROR_STREAM_OUT,
                ERROR_NULL_FILE
                }status_t;


#endif
