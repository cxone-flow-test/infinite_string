#ifndef __INFINITE_STR_H__
#define __INFINITE_STR_H__

#ifdef SHARED
  #define ATTR __attribute__((visibility("default")))
#else
  #define ATTR 
#endif


class ATTR InfiniteString
{
  private:
  size_t m_size;
  char* m_pos;
  char* m_buf;

  void expand_buf_to(size_t sz);

  public:
  
    InfiniteString();
    ~InfiniteString();
    int size();

    InfiniteString& operator+=(const char* rhs);

    const char* c_str();
};



#endif

