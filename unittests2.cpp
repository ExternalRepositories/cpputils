#include "contrib/catch.hpp"

// this second unit exists mostly  to guard against duplicate symbol linker errors
#include "stringconvert.h"
#include "formatter.h"
#include "hexdumper.h"
#include "stringlibrary.h"
#include "argparse.h"
TEST_CASE("second linker object") {
    CHECK( string::convert<char>(std::string("abcd")) == std::string("abcd") );
    CHECK( stringformat("%i", 123) == "123" );
    std::stringstream buf;
    buf << hex::hexstring << std::setfill(' ') << hex::dumper("abcde", 5);
    CHECK( buf.str() == "61 62 63 64 65" );
    CHECK( stringcompare("abcd", "abcd") == 0 );
}
