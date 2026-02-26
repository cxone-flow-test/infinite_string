#include <malloc.h>
#include <string.h>
#include "infinite_str.h"


InfiniteString::InfiniteString() : m_size(0), m_pos(nullptr), m_buf(nullptr) 
{
}

InfiniteString::~InfiniteString()
{
}

void InfiniteString::expand_buf_to(size_t sz)
{
  if (m_buf == nullptr)
  {
    m_size = sz;
    m_buf = (char*)calloc(sizeof(char), m_size + 1);
    m_pos = m_buf;
  }
  else
  {
    char* old_buf = m_buf;
    size_t old_size = m_size;

    m_size += sz;
    m_buf = (char*)calloc(sizeof(char), m_size + 1);

    strncpy(m_buf, old_buf, old_size);
    m_pos = m_buf + (m_pos - old_buf);
  }
}


InfiniteString& InfiniteString::operator+=(const char* rhs)
{
  size_t len = strlen(rhs);
  expand_buf_to(len);
  strncpy(m_pos, rhs, len);
  m_pos += len;

  return *this;
}


int InfiniteString::size()
{
  return m_size;
}

const char* InfiniteString::c_str()
{
  return m_buf;
}
