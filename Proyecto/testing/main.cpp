#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>
#include <archivos.h>

int main(int argc, char** argv) {
    return Catch::Session().run(argc, argv);
}
