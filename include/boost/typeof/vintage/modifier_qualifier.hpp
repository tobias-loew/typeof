// Copyright (C) 2004 Peder Holt
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.boost.org/LICENSE_1_0.txt)

template<>
struct encode_impl<NO_MODIFIERS+n>
{
    template<typename V,typename T,typename Types>
    struct encoder {
        typedef void(*function_ptr)(
            sizer<NO_MODIFIERS+n>,
            typename mpl::next<V>::type,
            T*,
            Types
        );
        BOOST_STATIC_CONSTANT(unsigned,value=sizeof(encode(function_ptr(NULL))));

        friend sizer<NO_MODIFIERS+n> encode_value(const sizer<V::index>&,const sizer<V::pos>&);
    };
};

template<typename V,typename T,typename Types>
typename encode_modifier<V,T,Types>::encoded_type encode(void(*)(sizer<NO_MODIFIERS+n>,V,T BOOST_TYPEOF_qualifier *,Types));

template<>
struct decode_impl<NO_MODIFIERS+n>
{
    template<typename Iter>
    struct decoder {
        typedef typename decode_impl<Iter::value>::decoder<Iter::next> decode0;
        typedef typename decode0::type BOOST_TYPEOF_qualifier type;
        typedef typename decode0::iter iter;
    };
};
