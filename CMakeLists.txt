cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(DAP VERSION 3.11)

# Include Subdirectories
add_subdirectory(xlsxio)
add_subdirectory(rmath)
add_subdirectory(gsl)

# Define executable targets
add_executable(dap dap.c)
add_executable(dappp dappp.c sastrans.c sastrans1.c sastrans2.c sastrans3.c)

# Define library target
add_library(dapstat STATIC
    dap0.c machdep.c dap1.c dap2.c dap3.c dap4.c dap5.c dap6.c prob.c misc.c ps.c ps1.c
)

# Specify include directories for the library
target_include_directories(dap PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}  # Adjust this if headers are in a different directory
)

# Specify include directories for the executables if needed
target_include_directories(dappp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Specify the headers for installation
install(FILES dap.h dap1.h ps.h
    DESTINATION include
)

# Specify the no-install headers
set(NO_INSTALL_HEADERS
    dap_make.h
    externs.h
    ps.h
    sas.h
)

# Optionally, you can manage no-install headers as a source group or something similar
# if you want to keep them organized in an IDE.
source_group("No Install Headers" FILES ${NO_INSTALL_HEADERS})

