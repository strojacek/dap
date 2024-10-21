cmake_minimum_required(VERSION 3.10)

# Project name and version
project(ReadStat VERSION 1.0)

# Enable testing
enable_testing()

# Define library
add_library(readstat STATIC
    src/CKHashTable.c
    src/readstat_bits.c
    src/readstat_convert.c
    src/readstat_error.c
    src/readstat_io_unistd.c
    src/readstat_malloc.c
    src/readstat_metadata.c
    src/readstat_parser.c
    src/readstat_value.c
    src/readstat_variable.c
    src/readstat_writer.c
    src/sas/ieee.c
    src/sas/readstat_sas.c
    src/sas/readstat_sas7bcat_read.c
    src/sas/readstat_sas7bcat_write.c
    src/sas/readstat_sas7bdat_read.c
    src/sas/readstat_sas7bdat_write.c
    src/sas/readstat_sas_rle.c
    src/sas/readstat_xport.c
    src/sas/readstat_xport_read.c
    src/sas/readstat_xport_write.c
    src/sas/readstat_xport_parse_format.c
    src/spss/readstat_por.c
    src/spss/readstat_por_parse.c
    src/spss/readstat_por_read.c
    src/spss/readstat_por_write.c
    src/spss/readstat_sav.c
    src/spss/readstat_sav_compress.c
    src/spss/readstat_sav_parse.c
    src/spss/readstat_sav_parse_timestamp.c
    src/spss/readstat_sav_parse_mr_name.c
    src/spss/readstat_sav_read.c
    src/spss/readstat_sav_write.c
    src/spss/readstat_spss.c
    src/spss/readstat_spss_parse.c
    src/stata/readstat_dta.c
    src/stata/readstat_dta_parse_timestamp.c
    src/stata/readstat_dta_read.c
    src/stata/readstat_dta_write.c
    src/txt/commands_util.c
    src/txt/readstat_copy.c
    src/txt/readstat_sas_commands_read.c
    src/txt/readstat_spss_commands_read.c
    src/txt/readstat_schema.c
    src/txt/readstat_stata_dictionary_read.c
    src/txt/readstat_txt_read.c
)

# Check for ZLIB
find_package(ZLIB)
if(ZLIB_FOUND)
    target_compile_definitions(readstat PRIVATE HAVE_ZLIB=1)
    target_sources(readstat PRIVATE
        src/spss/readstat_zsav_compress.c
        src/spss/readstat_zsav_read.c
        src/spss/readstat_zsav_write.c
    )
    target_link_libraries(readstat PRIVATE ZLIB::ZLIB)
endif()

# Include directories
target_include_directories(readstat PUBLIC src)

# Compiler flags
target_compile_options(readstat PRIVATE
    -g
    -Wall
    -Werror
    -pedantic-errors
    -std=c99
)

# Define executables
add_executable(readstat
    src/bin/readstat.c
    src/bin/read_csv/jsmn.c
    src/bin/read_csv/json_metadata.c
    src/bin/read_csv/mod_csv.c
    src/bin/read_csv/mod_dta.c
    src/bin/read_csv/mod_sav.c
    src/bin/read_csv/value.c
    src/bin/write/double_decimals.c
    src/bin/write/mod_csv.c
    src/bin/write/mod_readstat.c
    src/bin/write/module_util.c
    src/bin/util/file_format.c
    src/bin/util/quote_and_escape.c
    src/bin/util/readstat_dta_days.c
    src/bin/util/readstat_sav_date.c
)

target_link_libraries(readstat PRIVATE readstat)

# Other binaries
add_executable(extract_metadata
    src/bin/extract_metadata.c
    src/bin/write/json/write_missing_values.c
    src/bin/write/json/write_value_labels.c
    src/bin/util/file_format.c
    src/bin/util/quote_and_escape.c
    src/bin/util/readstat_dta_days.c
    src/bin/util/readstat_sav_date.c
)

target_link_libraries(extract_metadata PRIVATE readstat)

# Testing targets
add_executable(test_readstat
    src/test/test_buffer.c
    src/test/test_buffer_io.c
    src/test/test_dta.c
    src/test/test_error.c
    src/test/test_read.c
    src/test/test_readstat.c
    src/test/test_sas.c
    src/test/test_sav.c
    src/test/test_write.c
)

target_link_libraries(test_readstat PRIVATE readstat)

# Define other test executables similarly
# ...

# Install targets
install(TARGETS readstat extract_metadata
    DESTINATION bin
)

install(FILES
    src/readstat.h
    DESTINATION include
)

install(FILES
    src/CKHashTable.h
    src/readstat_bits.h
    src/readstat_convert.h
    src/readstat_iconv.h
    src/readstat_io_unistd.h
    src/readstat_malloc.h
    src/readstat_strings.h
    src/readstat_writer.h
    src/sas/ieee.h
    src/sas/readstat_sas.h
    src/sas/readstat_sas_rle.h
    src/sas/readstat_xport.h
    src/sas/readstat_xport_parse_format.h
    src/spss/readstat_por.h
    src/spss/readstat_por_parse.h
    src/spss/readstat_sav.h
    src/spss/readstat_sav_compress.h
    src/spss/readstat_sav_parse.h
    src/spss/readstat_sav_parse_timestamp.h
    src/spss/readstat_sav_parse_mr_name.h
    src/spss/readstat_spss.h
    src/spss/readstat_spss_parse.h
    src/spss/readstat_zsav_compress.h
    src/spss/readstat_zsav_read.h
    src/spss/readstat_zsav_write.h
    src/stata/readstat_dta.h
    src/stata/readstat_dta_parse_timestamp.h
    src/txt/commands_util.h
    src/txt/readstat_copy.h
    src/txt/readstat_schema.h
    src/bin/extract_metadata.h
    # Add all other header files here
    DESTINATION include
)

