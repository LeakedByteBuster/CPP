#if !defined(ITER_HPP)
#define ITER_HPP

template <typename Ptr, typename Len, typename Fun>
void    iter(Ptr *p, Len d, Fun func){
        for (int i = 0; i < d; i++)
                func(p[i]);
    return ;
}

#endif // ITER_HPP