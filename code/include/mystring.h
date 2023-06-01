#ifndef string_h
#define string_h

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief 字符串最大长度
 * 
 */
#define stringMaxSize 40

typedef struct string
{
    wchar_t* mBuffer;
    size_t mLength;
    size_t mSize;
} string;

/**
 * @brief 创建一个字符串
 * 
 * @param self 字符串对象
 * @param str 字符串内容
 */
void string_init(string* self, const char* str);

/**
 * @brief 查找子串的开始下标
 * 
 * @param patten 模式串
 * @param str 子串
 * @return int 子串在模式串中的开始位置下标
 */
int string_index(string *patten, string *str);

/**
 * @brief 转换为 const char＊
 * 
 * @param self 
 * @return const char* 
 */
const char* string_str(string* self);

/**
 * @brief 末尾添加一个字符
 * 
 * @param self 
 * @param c 
 */
void string_push_back(string* self, char c);

/**
 * @brief 字符串拷贝
 * 
 * @param dst 目的串
 * @param src 源串
 */
void string_copy(string* dst, string* src);

/**
 * @brief 字符串比较
 * 
 * @param dst 串1
 * @param src 串2
 * @return int 相同 0 不相同 1
 */
int string_cmp(string* dst, string* src);

/**
 * @brief 字符串拼接
 * 
 * @param dst 目的串
 * @param src 源串
 */
void string_add(string* dst, string* src);

/**
 * @brief 删除末尾字符
 * 
 * @param self 
 */
void string_pop_back(string* self);

/**
 * @brief 字符串是否为空
 * 
 * @param self 
 * @return int 
 */
int string_empty(string* self);

/**
 * @brief 字符串清空
 * 
 * @param self 
 * @return int 
 */
int string_clear(string* self);

/**
 * @brief 当前字符串的长度
 * 
 * @param self 
 * @return int 
 */
int string_length(string* self);

/**
 * @brief 字符串销毁
 * 
 * @param self 
 */
void string_destory(string* self);

/**
 * @brief 获取指定位置的字符
 * 
 * @param self 
 */
char string_get(string* self, size_t index);

/**
 * @brief 打印字符串
 * 
 * @param self 
 */
void string_print(string* self);

#endif