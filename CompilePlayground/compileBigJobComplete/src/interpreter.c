#define _CRT_SECURE_NO_WARNINGS
#define NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "interpreter.h"

typedef struct Pair
{
  char *key;
  enum fct value; // fct为不同指令种类
} Pair;

Pair fct_arr[] = {"cal", cal, "ckb", ckb, "int", Int, "jmp", jmp, "jp0", jp0,
                  "jp1", jp1, "jpc", jpc, "lda", lda, "lit", lit, "lod", lod,
                  "opr", opr, "ppa", ppa, "rva", rva, "sta", sta, "sto", sto};

static int cmp(const void *key, const void *pair)
{
  return strcmp((char *)key, ((Pair *)pair)->key);
}

/*
** s 是 fct 的字符串形式
*/
// void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
/*
key -- 指向要查找的元素的指针，类型转换为 void*。
base -- 指向进行查找的数组的第一个对象的指针，类型转换为 void*。
nitems -- base 所指向的数组中元素的个数。
size -- 数组中每个元素的大小，以字节为单位。
compar -- 用来比较两个元素的函数。
*/
enum fct str2fct(char *s)
{
  Pair *p = (Pair *)bsearch(s, fct_arr, sizeof fct_arr / sizeof *fct_arr,
                            sizeof *fct_arr, cmp);
  assert(NULL != p);
  return p->value;
}

long base(long b, long l)
{
  long b1 = b;
  while (l > 0)
  { // find base l levels down
    b1 = s[b1];
    --l;
  }
  return b1;
}

void interpret(instruction *code)
{
  long pre_p = 0;   // 记录 pc
  long p = 0;       // program count
  long b = 1;       // base register
  long t = 0;       // topstack register(指向栈顶，非下一位置，s[0]不用)
  instruction i;    // instruction register	float fa = 0;	// 为操作浮点数
  long registr = 0; // 放函数返回值

  long first = 0; // for reverse arguments
  long last = 0;

  float fa = .0f;
  float fb = .0f;
  size_t fsize = sizeof(float);
  assert(sizeof(long) == sizeof(float));

  printf("start PL/0\n");
  s[1] = 0;
  s[2] = 0;
  s[3] = 0;
  do
  {
    i = code[p]; // 都当前指令
    pre_p = p;
    ++p; // program count +=1
    switch (i.f)
    {
    case lit:  /*将a的值取到栈顶*/
      ++t;
      s[t] = i.a; // a 表示字面值常量
      break;
    case opr:
      switch (i.a)
      {       // operator
      case 0: // return  /*释放内存*/
        t = b - 1;
        p = s[t + 3]; // RA=return address
        b = s[t + 2]; // DL
        break;
      case 1:
        s[t] = -s[t]; /*取负*/
        break;
      case 2:
        --t;
        s[t] += s[t + 1]; /*加法*/
        break;
      case 3:
        --t;
        s[t] -= s[t + 1]; /*减法*/
        break;
      case 4:
        --t;
        s[t] *= s[t + 1]; /*乘法*/
        break;
      case 5:
        --t;
        s[t] /= s[t + 1]; /*除法*/
        break;
      case 6:
        s[t] %= 2; /*奇偶判断，奇数为真，偶数为假*/
        break;
      case 8:
        --t;
        s[t] = (s[t] == s[t + 1]); /*判断是否相等*/
        assert(s[t] == 1 || s[t] == 0);
        break;
      case 9:
        --t;
        s[t] = (s[t] != s[t + 1]); /*判断是否不等*/
        assert(s[t] == 1 || s[t] == 0);
        break;
      case 10:
        --t;
        s[t] = (s[t] < s[t + 1]); /*判断是否小于*/
        break;
      case 11:
        --t;
        s[t] = (s[t] >= s[t + 1]); /*判断是否大于等于*/
        break;
      case 12:
        --t;
        s[t] = (s[t] > s[t + 1]); /*判断是否大于*/
        break;
      case 13:
        --t;
        s[t] = (s[t] <= s[t + 1]); /*判断是否小于等于*/
        break;

      case 14:
        printf("%ld ", s[t]); // 暂时简单处理，直接输出一个空格 TODO:/*次栈顶值输出到屏幕*/
        --t;
        break;

      case 15:
        printf("\n"); /*输出换行符到屏幕*/
        break;

      case 16:
        // printf("请输入数据："); /*从命令行读入一个输入至栈顶*/
        ++t;
        scanf("%ld", &s[t]); // 增加类型后，应区别输入格式字符串
        break;

      case 17:
        memcpy(&fa, &s[t], fsize);
        printf("%.2f ", fa); // 默认保留2位小数
        break;

      case 18:
        memcpy(&fa, &s[t], fsize); // 实数类型取反
        fa = -fa;
        memcpy(&s[t], &fa, fsize);
        break;

      case 19:
        --t;   // 实数类型相加
        memcpy(&fa, &s[t], fsize);
        memcpy(&fb, &s[t + 1], fsize);
        fa += fb;
        memcpy(&s[t], &fa, fsize);
        break;

      case 20:
        --t; // 实数类型相减
        memcpy(&fa, &s[t], fsize);
        memcpy(&fb, &s[t + 1], fsize);
        fa -= fb;
        memcpy(&s[t], &fa, fsize);
        break;

      case 21:
        --t; // 实数类型相乘
        memcpy(&fa, &s[t], fsize);
        memcpy(&fb, &s[t + 1], fsize);
        fa *= fb;
        memcpy(&s[t], &fa, fsize);
        break;

      case 22:
        --t; // 实数类型相除
        memcpy(&fa, &s[t], fsize);
        memcpy(&fb, &s[t + 1], fsize);
        fa /= fb;
        memcpy(&s[t], &fa, fsize);
        break;

      case 23:
        ++t; // 实数类型输入
        scanf("%f", &fa);
        memcpy(&s[t], &fa, fsize);
        break;

      case 24:
        scanf("%*[^\n]%*c"); // or scanf("%*[^\n]");	// 下次读入数据时
                             // '\n' 会忽略
        break;

      case 26:
        --t;
        memcpy(&fa, &s[t], fsize);
        memcpy(&fb, &s[t + 1], fsize);
        s[t] = (fa < fb);
        break;

      case 27:
        --t;
        memcpy(&fa, &s[t], fsize);
        memcpy(&fb, &s[t + 1], fsize);
        s[t] = (fa >= fb);
        break;

      case 28:
        --t;
        memcpy(&fa, &s[t], fsize);
        memcpy(&fb, &s[t + 1], fsize);
        s[t] = (fa > fb);
        break;

      case 29:
        --t;
        memcpy(&fa, &s[t], fsize);
        memcpy(&fb, &s[t + 1], fsize);
        s[t] = (fa <= fb);
        break;

      case 30:
        fa = (float)(s[t]); // INTEGER 和 REAL 都是32位，将 INTEGER 隐式转换成
                            // REAL，可能丢失信息，下面同理
        memcpy(&s[t], &fa, fsize);
        break;

      case 31:
        fa = (float)(s[t - 1]);
        memcpy(&s[t - 1], &fa, fsize);
        break;

      case 32:
        --t;
        assert(s[t] == 1 || s[t] == 0);
        s[t] = s[t] || s[t + 1];
        assert(s[t] == 1 || s[t] == 0);
        break;

      case 33:
        --t;
        s[t] = s[t] && s[t + 1];
        break;

      case 34:
        s[t] = !s[t];
        break;

      case 35:
        --t;
        s[t] %= s[t + 1];
        break;

      case 36:
        registr = s[t--]; // 放函数返回值
        break;

      case 37:
        s[++t] = registr;
        break;

      default:
        assert(!"未定义的操作指令");
        break;
      }
      break;

    case lod: /*取相对当前过程的数据基地址为ａ的内存的值到栈顶*/
      ++t;
      s[t] = s[base(b, i.l) + i.a];
      break;

    case sto: /*栈顶的值存到相对当前过程的数据基地址为ａ的内存*/
      s[base(b, i.l) + i.a] = s[t];
      //	printf("%10d\n", s[t]);
      --t;
      break;

    case lda: /* 数组元素访问,当前栈顶为元素索引,执行后,栈顶变成元素的值 */
      s[t] = s[base(b, i.l) + i.a + s[t]];
      break;

    case sta: // store array element/* 栈顶的值存到数组中,索引为次栈顶 */
      s[base(b, i.l) + i.a + s[t - 1]] = s[t];
      t -= 2;
      break;

    case cal:                  // generate new block mark/*调用子程序*/
      s[t + 1] = base(b, i.l); // SL /*将父过程基地址入栈*/
      s[t + 2] = b;            // DL /*将本过程基地址入栈，此两项用于base函数*/
      s[t + 3] = p;            // RA /*将当前指令指针入栈*/
      b = t + 1;               // base 在 SL 的位置，都是 t+1 /*改变基地址指针值为新过程的基地址*/
      p = i.a;                 // callee 的入口地址 /*跳转*/
      break;

    case Int: /*分配内存*/
      t += i.a;
      break;

    case jmp: /*直接跳转*/
      p = i.a;
      break;
    case jpc: /*条件跳转*/
      if (s[t] == 0)
      {
        p = i.a;
      }
      --t;
      break;

    case jp0:
      if (s[t] == 0)
      {
        p = i.a;
      }
      break;

    case jp1:
      if (s[t] != 0)
      {
        p = i.a;
      }
      break;

    case ckb: // check bounds, 单独作为一条指令可能不合适
      if (!(s[t - 1] <= s[t - 2] && s[t - 2] < s[t]))
      {
        printf("ArrayIndexOutOfBoundsException at instructon %ld\n", pre_p);
        system("pause");
        exit(1);
      }
      t -= 2;
      break;

    case ppa: // pop arguments, 函数调用完成后栈顶指针恢复到参数压栈前的位置，address域为参数个数
      t -= i.a;
      break;

    case rva: // reverse arguments(真正实现时可能不用这样)，address 域为参数个数
      first = t - i.a + 1;
      last = t + 1;
      if (last - first >= 2)
      {
        for (; first < (last--); ++first)
        {
          long tmp = s[first];
          s[first] = s[last];
          s[last] = tmp;
        }
      }

      break;

    default:
      assert(!"未定义的操作指令");
      break;
    }
  } while (p != 0);
  printf("end PL/0\n");
}

int main(int argc, char **argv)
{
  instruction code[cxmax + 1];
  long i = 0;
  char s_fct[INSTRUCTION_FUN_LEN + 1];
  FILE *fin = NULL;

  printf("Please input intermediate representation file name:\n");
  scanf("%s", infilename);
  fin = fopen(infilename, "r");
  if (fin == NULL)
  {
    printf("Can't open file %s.\n", infilename);
    system("pause");
    exit(1);
  }
  for (i = 0; i <= cxmax && EOF != fscanf(fin, "%s", s_fct); ++i)
  {
    code[i].f = str2fct(s_fct);
    fscanf(fin, "%ld%ld", &(code[i].l), &(code[i].a));
  }
  if (i > cxmax)
  {
    printf("program too long\n");
    system("pause");
    exit(1);
  }

  interpret(code);

  fclose(fin);
  system("pause");
  return 0;
}