#ifndef COMMON_HPP
#define COMMON_HPP
using namespace std;
typedef enum{
                OK,
                ERROR_NULL_POINTER,
                ERROR_MEMORY_NO_AVAILABLE,
                OK_INPUT,OK_OUTPUT,
                ERROR_TEXT_LINE_INVALID,
                ROUTE_NAME_OK,
                ERROR_ROUTE_NAME_INVALID,
                ERROR_NO_ARGS,
                ERROR_INVALID_INPUT_ROUTE,
                ERROR_INVALID_OUTPUT_ROUTE,
                ERROR_INVALID_ARGUMENT,
                ERROR_STREAM_OUT
                }status_t;


#endif
