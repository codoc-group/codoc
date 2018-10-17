#
# codoc blacktriangles (c) 2018
#

codoc_add_test(
    NAME config_test
    SOURCES
        document_test.cc
    DATA
        config_test.yml
    PRIVATE_DEPS
        config
)
