// Copyright (c) 2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/json/

#ifndef TAOCPP_JSON_INCLUDE_EVENTS_KEY_SNAKE_CASE_TO_CAMEL_CASE_HPP
#define TAOCPP_JSON_INCLUDE_EVENTS_KEY_SNAKE_CASE_TO_CAMEL_CASE_HPP

#include <string>

namespace tao
{
   namespace json
   {
      namespace events
      {
         template< typename Consumer >
         struct key_snake_case_to_camel_case
            : public Consumer
         {
            using Consumer::Consumer;

            void key( const std::string& v )
            {
               std::string r;
               r.reserve( v.size() );
               bool active = false;
               for( const auto c : v ) {
                  if( active ) {
                     if( c == '_' ) {
                        r += c;
                     }
                     else if( std::isupper( c ) ) {
                        r += '_';
                        r += c;
                        active = false;
                     }
                     else {
                        r += std::toupper( c );
                        active = false;
                     }
                  }
                  else {
                     if( c == '_' ) {
                        active = true;
                     }
                     else {
                        r += c;
                     }
                  }
               }
               if( active ) {
                  r += '_';
               }
               Consumer::key( std::move( r ) );
            }
         };

      }  // namespace events

   }  // namespace json

}  // namespace tao

#endif
