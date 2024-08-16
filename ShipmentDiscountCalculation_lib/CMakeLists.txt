project(ShipmentDiscountCalculation)

set(HEADER_FILES
        functions.h
)

set(SOURCE_FILES
        functions.cpp
)

add_library(ShipmentDiscountCalculation_lib STATIC ${SOURCE_FILES})