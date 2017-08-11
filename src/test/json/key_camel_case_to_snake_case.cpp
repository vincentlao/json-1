// Copyright (c) 2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/json/

#include "test.hpp"

#include <tao/json/events/key_camel_case_to_snake_case.hpp>
#include <tao/json/to_string.hpp>

namespace tao
{
   namespace json
   {
      void test( const value& v, const std::string& s )
      {
         std::cout << to_string( v ) << ": " << s << " == " << to_string< events::key_camel_case_to_snake_case >( v ) << std::endl;
         TEST_ASSERT( to_string< events::key_camel_case_to_snake_case >( v ) == s );
      }

      void unit_test()
      {
         test( { { "fooBar", 42 } }, "{\"foo_bar\":42}" );
         test( { { "foo2Bar", 42 } }, "{\"foo2_bar\":42}" );
         test( { { "fooHTTPBar", 42 } }, "{\"foo_http_bar\":42}" );
         test( { { "HTTPBar", 42 } }, "{\"http_bar\":42}" );

         test( { { "fooBar", "fooBar" } }, "{\"foo_bar\":\"fooBar\"}" );

         test( { { "foo_", 42 } }, "{\"foo_\":42}" );
         test( { { "foo_bar", 42 } }, "{\"foo_bar\":42}" );
         test( { { "_foo", 42 } }, "{\"_foo\":42}" );

         test( { { "Foo", 42 } }, "{\"foo\":42}" );
         test( { { "_Foo", 42 } }, "{\"_foo\":42}" );
         test( { { "foo_Bar", 42 } }, "{\"foo_bar\":42}" );
      }

   }  // namespace json

}  // namespace tao

#include "main.hpp"