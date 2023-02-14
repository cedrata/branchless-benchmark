target_sources(comparason
    INTERFACE FILE_SET HEADERS
    BASE_DIRS ${PROJECT_SOURCE_DIR}/src
    FILES branched.h branchless.h
)