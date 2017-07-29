// Copyright (c) 2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/json/

#ifndef TAOCPP_JSON_INCLUDE_EVENTS_TRANSFORMER_HPP
#define TAOCPP_JSON_INCLUDE_EVENTS_TRANSFORMER_HPP

namespace tao
{
   namespace json
   {
      namespace events
      {
         namespace detail
         {
            template< typename Consumer, template< typename... > class... Transformer >
            struct transformer;

            template< typename Consumer >
            struct transformer< Consumer >
            {
               using type = Consumer;
            };

            template< typename Consumer, template< typename... > class Head, template< typename... > class... Tail >
            struct transformer< Consumer, Head, Tail... >
            {
               using type = Head< typename transformer< Consumer, Tail... >::type >;
            };

         }  // namespace detail

         template< typename Consumer, template< typename... > class... Transformer >
         using transformer = typename detail::transformer< Consumer, Transformer... >::type;

      }  // namespace events

   }  // namespace json

}  // namespace tao

#endif