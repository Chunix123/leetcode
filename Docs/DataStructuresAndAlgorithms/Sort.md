# 1. 排序算法分类

&emsp;&emsp;**在计算机科学所使用的排序算法通常被分类为:**

1. 计算的时间复杂度（最差、平均、和最好性能），依据列表（list）的大小(n)。一般而言，好的性能是 O(nlogn)(大O符号)，坏的性能是 O(n^2)。对于一个排序理想的性能是 O(n)，但平均而言不可能达到。基于比较的排序算法对大多数输入而言至少需要 O(nlogn)。
2. 内存使用量（以及其他计算机资源的使用）。
3. 稳定性：稳定排序算法会让原本有相等键值的纪录维持相对次序。也就是如果一个排序算法是稳定的，当有两个相等键值的纪录 R和 S，且在原本的列表中 R出现在 S之前，在排序过的列表中 R也将会是在 S之前。
4. 依据排序的方法：插入、交换、选择、合并等等。

## 1.1 稳定性

&emsp;&emsp;稳定排序算法会依照相等的关键（换言之就是值）维持纪录的相对次序。也就是一个排序算法是稳定的，就是当有两个有相等关键的纪录R和S，且在原本的串行中R出现在S之前，在排序过的串行中R也将会是在S之前。

## 1.2 计算复杂度

- 依据串行（list）的大小（n），一般而言，好的表现是O(nlogn)，且坏的行为是O(n2)。对于一个排序理想的表现是O(n)。仅使用一个抽象关键比较运算的排序算法总平均上总是至少需要O(nlogn)。
- 所有基于比较的排序的时间复杂度至少是 O(nlogn)。

## 1.3 常用排序算法

|  排序方法  | 时间复杂度（平均） | 时间复杂度（最坏） | 时间复杂度（最好） | 空间复杂度 | 稳定性 |
| :--------: | :----------------: | :----------------: | :----------------: | :--------: | :----: |
|  冒泡排序  |       O(n^2)       |       O(n^2)       |        O(n)        |    O(1)    |  稳定  |
|  插入排序  |       O(n^2)       |       O(n^2)       |        O(n)        |    O(1)    |  稳定  |
|  选择排序  |       O(n^2)       |       O(n^2)       |       O(n^2)       |    O(1)    | 不稳定 |
|  快速排序  |      O(nlogn)      |       O(n^2)       |      O(nlogn)      |  O(nlogn)  | 不稳定 |
|  希尔排序  |      O(nlogn)      |       O(n^2)       |        O(n)        |    O(1)    | 不稳定 |
|   堆排序   |      O(nlogn)      |      O(nlogn)      |      O(nlogn)      |    O(1)    | 不稳定 |
|  归并排序  |      O(nlogn)      |      O(nlogn)      |      O(nlogn)      |    O(n)    |  稳定  |
|   桶排序   |       O(n+k)       |       O(n^2)       |        O(n)        |   O(n+k)   |  稳定  |
|  基数排序  |       O(n*k)       |       O(n*k)       |       O(n*k)       |   O(n+k)   |  稳定  |
|  计数排序  |       O(n+k)       |       O(n+k)       |       O(n+k)       |   O(n+k)   |  稳定  |

# 2. 常见排序算法

​	**常见的稳定排序算法有：**

- 冒泡排序（Bubble Sort） — O(n²)

- 插入排序（Insertion Sort）— O(n²)

- 桶排序（Bucket Sort）— O(n); 需要 O(k) 额外空间

- 计数排序 (Counting Sort) — O(n+k); 需要 O(n+k) 额外空间

- 合并排序（Merge Sort）— O(nlogn); 需要 O(n) 额外空间

- 基数排序（Radix sort）— O(n·k); 需要 O(n) 额外空间

  **常见的不稳定排序算法有：**

- 选择排序（Selection Sort）— O(n²)

- 希尔排序（Shell Sort）— O(nlogn)

- 堆排序（Heapsort）— O(nlogn)

- 快速排序（Quicksort）— O(nlogn) 期望时间, O(n²) 最坏情况; 对于大的、乱数串行一般相信是最快的已知排序

### 2.1 冒泡排序

- 冒泡排序（**Bubble Sort**）是最简单最容易理解的排序算法之一，它是基于比较的排序算法，其思想是通过无序区中相邻记录关键字间的比较和位置的交换,使关键字最小的记录如气泡一般逐渐往上“漂浮”直至“水面”。

- 冒泡排序的复杂度：在最好情况下，即正序有序，则只需要比较n次，故为O(n) ；最坏情况下，即逆序有序，则需要比较(n-1)+(n-2)+……+1，故为O(n²)。

- 算法原理是相邻的数据进行两两比较，小数放在前面，大数放在后面，这样一趟下来，最大的数就被排在了最后一位，第二趟也是如此，如此类推，直到所有的数据排序完成：

  1. 比较相邻的元素。如果第一个比第二个大，就交换它们两个；
  2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
  3. 针对所有的元素重复以上的步骤，除了最后一个；
  4. 重复步骤1~3，直到排序完成。

- 乌龟和兔子：在冒泡排序中，最大元素的移动速度是最快的，哪怕一开始最大元素处于序列开头，也可以在一轮内层循环之后，移动到序列末尾。而对于最小元素，每一轮内层循环只能向前挪动一位，如果最小元素在序列末尾，就需要 n-1 次交换才能移动到序列开头。这两种类型的元素分别被称为兔子和乌龟。

- C代码实现

  ```c
  void bubble_sort(int *arr, int len)
  {
      int i, j;
      
      for (i = 0; i < len - 1; i++)
      {
          for (j = 0; j < len - 1; j++)
          {
              if (arr[j] > arr[j + 1])
              {
                  int temp = arr[j + 1];
                  arr[j + 1] = arr[j];
                  arr[j] = temp;
              }
          }
      }
  }
  ```

- 优化：在非最坏的情况下，冒泡排序过程中，可以检测到整个序列是否已经排序完成，进而可以避免掉后续的循环；

  ```c
  void bubble_sort(int *arr, int len)
  {
      bool flag = false;
      int i, j;
      
      for (i = 0; i < len - 1; i++)
      {
          for (j = 0; j < len - 1; j++)
          {
              if (arr[j] > arr[j + 1])
              {
                  flag = true;
                  int temp = arr[j + 1];
                  arr[j + 1] = arr[j];
                  arr[j] = temp;
              }
          }
          
          if(!flag)
              break;
      }
  }
  ```

- 进一步地，在每轮循环之后，可以确认，最后一次发生交换的位置之后的元素，都是已经排好序的，因此可以不再比较那个位置之后的元素，大幅度减少了比较的次数：

  ```c
  void bubble_sort(int *arr, int len)
  {
      int i, j, new, n = len;
      
      for (i = 0; i < len - 1; i++)
      {
          new = 0;
          for (j = 0; j < n - 1; j++)
          {
              if (arr[j] > arr[j + 1])
              {
                  int temp = arr[j + 1];
                  arr[j + 1] = arr[j];
                  arr[j] = temp;
                  new = j + 1;
              }
          }
          n = new;
          
          if(n == 0)
              break;
      }
  }
  ```

- 更进一步地，为了优化之前提到的乌龟和兔子问题，可以进行双向的循环，正向循环把最大元素移动到末尾，逆向循环把最小元素移动到最前，这种优化过的冒泡排序，被称为**鸡尾酒排序**：

  ```c
  void bubble_sort(int *arr, int len)
  {
      int j, begin = 0, end = len - 1;
  
      while(begin <= end)
      {
          int nbegin = end;
          int nend = begin;
  
          for(j = begin; j < end; j++)
          {
              if (arr[j] > arr[j + 1])
              {
                  int temp = arr[j + 1];
                  arr[j + 1] = arr[j];
                  arr[j] = temp;
                  nend = j + 1;
              }
          }
          end = nend - 1;
  
          for(j = end; j > begin - 1; j--)
          {
              if (arr[j] > arr[j + 1])
              {
                  int temp = arr[j + 1];
                  arr[j + 1] = arr[j];
                  arr[j] = temp;
                  nbegin = j;
              }
          }
          begin = nbegin + 1;
      }
  }
  ```

### 2.2 插入排序

+ 插入排序（**Insertion-Sort**）是一种简单直观的排序算法。通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。

+ 插入排序的思想是，每次只处理一个元素，从后往前查找，找到该元素合适的插入位置，最好的情况下，即正序有序(从小到大)，这样只需要比较n次，不需要移动。因此时间复杂度为O(n) ，最坏的情况下，即逆序有序，这样每一个元素就需要比较n次，共有n个元素，因此实际复杂度为O(n²) 。

+ 算法原理：将数据分为两部分，有序部分与无序部分，一开始有序部分包含第1个元素，依次将无序的元素插入到有序部分，直到所有元素有序。插入排序又分为直接插入排序、二分插入排序、链表插入等，这里只讨论直接插入排序。它是稳定的排序算法，时间复杂度为O(n^2)。

+ 算法描述：
  1. 从第一个元素开始，该元素可以认为已经被排序；
  2. 取出下一个元素，在已经排序的元素序列中从后向前扫描；
  3. 如果该元素（已排序）大于新元素，将该元素移到下一位置；
  4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
  5. 将新元素插入到该位置后；
  6. 重复步骤2~5。

+ C代码实现：

  ```c
  void insertionSort(int *arr, int len)
  {
      int i = 1, j;
  
      while(i < len)
      {
          j = i;
          while(j > 0 && arr[j - 1] > arr[j])
          {
              int temp = arr[j];
              arr[j] = arr[j - 1];
              arr[j - 1] = temp;
              j--;
          }
          i++;
      }
  }
  ```

### 2.3 选择排序

+ 选择排序（**Selection-sort**)）是一种简单直观的排序算法。它的工作原理：首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。 

+ 算法描述：n个记录的直接选择排序可经过n-1趟直接选择排序得到有序结果。具体算法描述如下：

  1. 初始状态：无序区为R[1..n]，有序区为空；
  2. 第i趟排序(i=1,2,3…n-1)开始时，当前有序区和无序区分别为R[1..i-1]和R(i..n）。该趟排序从当前无序区中-选出关键字最小的记录 R[k]，将它与无序区的第1个记录R交换，使R[1..i]和R[i+1..n)分别变为记录个数增加1个的新有序区和记录个数减少1个的新无序区；
  3. n-1趟结束，数组有序化了。

+ C代码实现：

  ```c
  void selectSort(int *arr, int len)
  {
      int i, j, index;
  
      for(i = 0; i < len; i++)
      {
          index = i;
  
          for(j = i + 1; j < len; j++)
          {
              if(arr[j] < arr[index])
                  index = j;
          }
  
          if(index != i)
          {
              int temp = arr[i];
              arr[i] = arr[index];
              arr[index] = temp;
          }
      }
  }
  ```

### 2.4 快速排序

+ 快速排序（**Quick Sort**）是目前在实践中非常高效的一种排序算法，它不是稳定的排序算法，平均时间复杂度为O(nlogn)，最差情况下复杂度为O(n^2)。

+ 快速排序的基本思想：通过一趟排序将待排记录分隔成独立的两部分，其中一部分记录的关键字均比另一部分的关键字小，则可分别对这两部分记录继续进行排序，以达到整个序列有序。

+ 算法复杂度：因为每次都将序列分为两个部分，故为 O(N * logN)；基本有序时，退化为冒泡排序，几乎要比较N*N次，故为O(N * N)。

+ 算法描述：快速排序使用分治法来把一个串（list）分为两个子串（sub-lists）。具体算法描述如下：

  1. 从数列中挑出一个元素，称为 “基准”（pivot）；
  2. 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
  3. 递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。

+ C代码实现：

  ```c
  void quickSort(int *arr, int left, int right)
  {
      if(left < right)
      {
          int i = left, j = right, target = arr[left];
  
          while(i < j)
          {
              while(i < j && arr[j] > target)
                  j--;
              if(i < j)
                  arr[i++] = arr[j];
  
              while(i < j && arr[i] < target)
                  i++;
              if(i < j)
                  arr[j] = arr[i];
          }
  
          arr[i] = target;
          quickSort(arr, left, i - 1);
          quickSort(arr, i + 1, right);
      }
  }
  ```

### 2.5 希尔排序

+ 希尔排序（**Shell Sort**）是简单插入排序的改进版。它与插入排序的不同之处在于，它会优先比较距离较远的元素。希尔排序又叫缩小增量排序。

+ 算法描述：先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，具体算法描述：

  1.  选择一个增量序列t1，t2，…，tk，其中ti>tj，tk=1；
  2.  按增量序列个数k，对序列进行k 趟排序；
  3.  每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m 的子序列，分别对各子表进行直接插入排序。仅增量因子为1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。

+ 时间复杂度：由于希尔排序的好坏和步长d的选择有很多关系，因此，目前还没有得出最好的步长如何选择。所以，不知道最好的情况下的算法时间复杂度。最坏情况下：O(N*logN)，最坏的情况下和平均情况下差不多。

+ 由于多次插入排序，我们知道一次插入排序是稳定的，不会改变相同元素的相对顺序，但在不同的插入排序过程中，相同的元素可能在各自的插入排序中移动，最后其稳定性就会被打乱，所以shell排序是不稳定的。

+ C代码实现：

  ```c
  void shellSort(int *arr, int len)
  {
      int i, j, d = len / 2;
  
      while(d > 0)
      {
          for(i = d; i < len; i++)
          {
              j = i - d;
              while(j >= 0 && arr[j] > arr[j + d])
              {
                  int temp = arr[j];
                  arr[j] = arr[j + d];
                  arr[j + d] = temp;
                  j = j - d;
              }
          }
  
          d = d / 2;
      }
  }
  ```

### 2.6 堆排序

+ 堆排序（**Heapsort**）是指利用堆这种数据结构所设计的一种排序算法。堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：

  1. 父结点的键值总是大于或等于(小于或等于)任何一个子节点的键值；
  2. 每个结点的左子树和右子树都是一个二叉堆

+ 当父结点的键值总是大于或等于任何一个子节点的键值时为最大堆。当父结点的键值总是小于或等于任何一个子节点的键值时为最小堆。一般二叉树简称为堆。

+ 堆的存储：堆可以用数组来表示，这是因为堆是完全二叉树，而完全二叉树很容易就存储在数组中。位置 k 的节点的父节点位置为 k/2，而它的两个子节点的位置分别为 2k 和 2k+1。这里不使用数组索引为 0 的位置，是为了更清晰地描述节点的位置关系。

+ 算法描述：

  1. 将初始待排序关键字序列(R1,R2….Rn)构建成大顶堆，此堆为初始的无序区；
  2. 将堆顶元素R[1]与最后一个元素R[n]交换，此时得到新的无序区(R1,R2,……Rn-1)和新的有序区(Rn),且满足R[1,2…n-1]<=R[n]；
  3. 由于交换后新的堆顶R[1]可能违反堆的性质，因此需要对当前无序区(R1,R2,……Rn-1)调整为新堆，然后再次将R[1]与无序区最后一个元素交换，得到新的无序区(R1,R2….Rn-2)和新的有序区(Rn-1,Rn)。不断重复此过程直到有序区的元素个数为n-1，则整个排序过程完成。

+ 一个堆的高度为 logN，因此在堆中插入元素和删除最大元素的复杂度都为 logN。对于堆排序，由于要对 N 个节点进行下沉操作，因此复杂度为 NlogN。堆排序是一种原地排序，没有利用额外的空间。

+ C代码实现：

  ```c
  void heap_adjust(int *arr, int i, int len)
  {
      int child, temp;
  
      for(; 2 * i + 1 < len; i = child)
      {
          //child pos = 2 * par + 1;
          child = 2 * i + 1;
  
          if(child < len - 1 && arr[child + 1] > arr[child])
              child++;
  
          //If child.value > par.value move
          if(arr[i] < arr[child])
          {
              temp = arr[i];
              arr[i] = arr[child];
              arr[child] = temp;
          }
          else
              break;
      }
  }
  
  void heap_sort(int *arr, int len)
  {
      int i;
  
      for(i = len / 2 - 1; i >= 0; i--)
          heap_adjust(arr, i, len);
  
      for(i = len - 1; i > 0; i--)
      {
          int temp = arr[0];
          arr[0] = arr[i];
          arr[i] = temp;
  
          heap_adjust(arr, 0, i);
      }
  }
  ```

### 2.7 归并排序

+ 归并排序（**Merge Sort**）是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为2-路归并。 

+ 算法描述：

  1. 把长度为n的输入序列分成两个长度为n/2的子序列；
  2. 对这两个子序列分别采用归并排序；
  3. 将两个排序好的子序列合并成一个最终的排序序列。

+ 归并排序是稳定的排序算法，其时间复杂度为O(nlogn)，如果是使用链表的实现的话，空间复杂度可以达到O(1)，但如果是使用数组来存储数据的话，在归并的过程中，需要临时空间来存储归并好的数据，所以空间复杂度为O(n)。

+ 归并方法：

  1. 自顶向下归并排序：将一个大数组分成两个小数组去求解。因为每次都将问题对半分成两个子问题，这种对半分的算法复杂度一般为 O(NlogN)。
  2. 自顶向上归并排序：先归并那些微型数组，然后成对归并得到的微型数组。

+ C代码实现

  1. 自顶向下：递归实现（函数递归调用）

  ```c
  void merge(int *arr, int start, int mid, int end)
  {
      int n1 = mid - start + 1;
      int n2 = end - mid;
      int left[n1], right[n2];
      int i, j, k;
  
      for(i = 0; i < n1; i++)
          left[i] = arr[start + i];
  
      for(j = 0; j < n2; j++)
          right[j] = arr[mid + 1 + j];
  
      i = 0;
      j = 0;
      k = start;
  
      while(i < n1 && j < n2)
      {
          if(left[i] < right[j])
              arr[k++] = left[i++];
          else
              arr[k++] = right[j++];
      }
  
      while(i < n1)
          arr[k++] = left[i++];
  
      while(i < n2)
          arr[k++] = right[j++];
  }
  
  void merge_sort(int *arr, int start, int end)
  {
      if(start < end)
      {
          int mid = (start + end) / 2;
  
          merge_sort(arr, start, mid);
          merge_sort(arr, mid + 1, end);
          merge(arr, start, mid, end);
      }
  }
  ```

  2. 自底向上：非递归实现

  ```c
  void merge_sort2(int *arr, int len)
  {
      int i, left_min, left_max, right_min, right_max, next;
      int *temp = (int *) malloc(sizeof(int) * len);
  
      if (temp == NULL)
      {
          fputs("Error: out of memory\n", stderr);
          abort();
      }
  
      for (i = 1; i < len; i *= 2)
      {
          for(left_min = 0; left_min < len - 1; left_min = right_max)
          {
              left_max = left_min + i;
              right_min = left_max;
              right_max = left_max + i;
  
              if(right_max > len)
                  right_max = len;
  
              next = 0;
  
              while(left_min < left_max && right_min < right_max)
                  temp[next++] = arr[left_min] > arr[right_min] ? arr[right_min++] : arr[left_min++];
  
              while(left_min < left_max)
                  arr[--right_min] = arr[--left_max];
  
              while(next > 0)
                  arr[--right_min] = temp[--next];
          }
      }
  
      free(temp);
  }
  ```

### 2.8 计数排序

+ 计数排序（**Counting Sort**）不是基于比较的排序算法，其核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。 作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数。

+ 计数排序是一个稳定的排序算法。当输入的元素是 n 个 0到 k 之间的整数时，时间复杂度是O(n+k)，空间复杂度也是O(n+k)，其排序速度快于任何比较排序算法。当k不是很大并且序列比较集中时，计数排序是一个很有效的排序算法。

+ 算法描述：

  1. 找出待排序的数组中最大和最小的元素；
  2. 统计数组中每个值为i的元素出现的次数，存入数组C的第i项；
  3. 对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）；
  4. 反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1。

+ C代码实现：

  ```c
  void count_sort(int *arr, int len)
  {
      int i, maxValue = arr[0];
  
      for(i = 0; i < len; i++)
      {
          if(arr[i] > maxValue)
              maxValue = arr[i];
      }
      
      maxValue += 1;
  
      int *countArr = (int *)malloc(maxValue * sizeof(int));
      int *sortsArr = (int *)malloc(len * sizeof(int));
  
      for(i = 0; i < len; i++)
          countArr[arr[i]]++;
  
      for(i = 1; i < maxValue; i++)
          countArr[i] += countArr[i - 1];
  
      for(i = len - 1; i >= 0; --i)
      {
          sortsArr[countArr[arr[i]] - 1] = arr[i];
          --countArr[arr[i]];
      }
  
      memcpy(arr, sortsArr, len * sizeof(int));
  
      free(sortsArr);
      free(countArr);
  }
  ```

### 2.9 桶排序

+ 桶排序（**Bucket sort**）是计数排序的升级版。它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。

+ 工作原理：假设输入数据服从均匀分布，将数据分到有限数量的桶里，每个桶再分别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排）。

+ 桶排序的基本思想：假设有一组长度为N的待排关键字序列K[1....n]。首先将这个序列划分成M个的子区间(桶) 。然后基于某种映射函数 ，将待排序列的关键字k映射到第i个桶中(即桶数组B的下标 i) ，那么该关键字k就作为B[i]中的元素(每个桶B[i]都是一组大小为N/M的序列)。接着对每个桶B[i]中的所有元素进行比较排序(可以使用快排)。然后依次枚举输出B[0]....B[M]中的全部内容即是一个有序序列。

+ 桶排序的平均时间复杂度为线性的O(N+C)，其中C=N*(logN-logM)。如果相对于同样的N，桶数量M越大，其效率越高，最好的时间复杂度达到O(N)。 当然桶排序的空间复杂度 为O(N+M)，如果输入数据非常庞大，而桶的数量也非常多，则空间代价无疑是昂贵的。此外，桶排序是稳定的。

+ 算法描述：

  1. 设置一个定量的数组当作空桶；
  2. 遍历输入数据，并且把数据一个一个放到对应的桶里去；
  3. 对每个不是空的桶进行排序；
  4. 从不是空的桶里把排好序的数据拼接起来。 

+ C代码实现

  ```c
  void bucket_sort(int *arr, int len)
  {
      if(arr == NULL || len < 1)
          return;
  
      int i, j, maxValue = arr[0];
  
      for(i = 1; i < len; i++)
      {
          if(maxValue < arr[i])
              maxValue = arr[i];
      }
      maxValue += 1;
  
      int buckets[maxValue];
  
      for(i = 0; i < maxValue; i++)
          buckets[i] = 0;
  
      for(i = 0; i < len; i++)
          buckets[arr[i]]++;
  
      for(i = 0, j = 0; i < maxValue; i++)
      {
          while((buckets[i]--) > 0)
              arr[j++] = i;
      }
  }
  ```

### 2.10 基数排序

+ 基数排序（**Radix Sort**）是是**桶排序**的扩展，按照低位先排序，然后收集；再按照高位排序，然后再收集；依次类推，直到最高位。有时候有些属性是有优先级顺序的，先按低优先级排序，再按高优先级排序。最后的次序就是高优先级高的在前，高优先级相同的低优先级高的在前。

+ 基本思想是：将整数按位数切割成不同的数字，然后按每个位数分别比较。具体做法是将所有待比较数值统一为同样的数位长度，数位较短的数前面补零。然后，从最低位开始，依次进行一次排序。这样从最低位排序一直到最高位排序完成以后, 数列就变成一个有序序列。

+ 算法描述：

  1. 取得数组中的最大数，并取得位数，按照个位数进行排序；
  2. arr为原始数组，从最低位开始取每个位组成radix数组；
  3. 对radix进行计数排序（利用计数排序适用于小范围数的特点）。

+ 基数排序基于分别排序，分别收集，所以是稳定的。但基数排序的性能比桶排序要略差，每一次关键字的桶分配都需要O(n)的时间复杂度，而且分配之后得到新的关键字序列又需要O(n)的时间复杂度。基数排序的空间复杂度为O(n+k)，其中k为桶的数量。一般来说n>>k，因此额外空间需要大概n个左右。

+ C代码实现：

  ```c
  int get_max(int a[], int n)
  {
      int i, max = a[0];
  
      for (i = 1; i < n; i++)
          if (a[i] > max)
              max = a[i];
  
      return max;
  }
  
  void count_sort(int a[], int n, int exp)
  {
      int output[n];
      int i, buckets[10] = {0};
  
      for (i = 0; i < n; i++)
          buckets[(a[i] / exp) % 10]++;
  
      for (i = 1; i < 10; i++)
          buckets[i] += buckets[i - 1];
  
      for (i = n - 1; i >= 0; i--)
      {
          output[buckets[(a[i] / exp) % 10] - 1] = a[i];
          buckets[(a[i] / exp) % 10]--;
      }
  
      for (i = 0; i < n; i++)
          a[i] = output[i];
  }
  
  void radix_sort(int *arr, int len)
  {
      int exp;
  
      int maxValue = get_max(arr, len);
  
      for(exp = 1; maxValue/exp > 0; exp++)
          count_sort(arr, len, exp);
  }
  ```

# 总结

+ 从平均时间来看，快速排序是效率最高的，但快速排序在最坏情况下的时间性能不如堆排序和归并排序。而后者相比较的结果是，在n较大时归并排序使用时间较少，但使用辅助空间较多。
+ 上面说的简单排序包括除希尔排序之外的所有冒泡排序、插入排序、简单选择排序。其中直接插入排序最简单，但序列基本有序或者n较小时，直接插入排序是好的方法，因此常将它和其他的排序方法，如快速排序、归并排序等结合在一起使用。
+ 基数排序的时间复杂度也可以写成O(d*n)。因此它最使用于n值很大而关键字较小的的序列。若关键字也很大，而序列中大多数记录的最高关键字均不同，则亦可先按最高关键字不同，将序列分成若干小的子序列，而后进行直接插入排序。
+ 从方法的稳定性来比较，基数排序是稳定的内排方法，所有时间复杂度为O(n^2)的简单排序也是稳定的。但是快速排序、堆排序、希尔排序等时间性能较好的排序方法都是不稳定的。稳定性需要根据具体需求选择。
+ 上面的算法实现大多数是使用线性存储结构，像插入排序这种算法用链表实现更好，省去了移动元素的时间。具体的存储结构在具体的实现版本中也是不同的。