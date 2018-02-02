# Get-links

> 通过输入的`OJ`和`ProblemID`，得到 `markdown` 形式的表格和链接

## 如何使用

1. 把`get-links.cpp`中的内容复制下来，在本地编译运行然后使用。
2. 下载`get-links.exe`，直接使用。
3. 如果采用文件输入的方式，请务必保证输入文件和`.exe`在同一路径下。

## 输入格式

1. 首先输入两个字符串`str_in`和`str_out`。(Example: problem.txt links)
   - `str_in`是输入文件，如果不想使用文件输入，请输入`no`。
   - `str_out`是输出文件，如果不想使用文件输出，请输入`no`。
   - 请注意**输出文件**中的`.*`会失效，最后的输出文件**总是以`.md`为后缀名**。

1. 然后再输入`OJ`和`ProblemID`，先输入`OJ`再输入`ProblemID`。(Example: BZOJ 1000)(可以无限输入)
   
   - 目前支持的`OJ`: `BZOJ`,`HDU`,`UOJ`,`LOJ`,`POJ`,`URAL`,`51Nod`,`CodeForces`,`Gym`,`SPOJ`,`洛谷`,`青橙`,`CodeChef`.

1. `OJ`的正确输入方式
   - 输入的`OJ`**不区分大小写**，`BzOj`和`bzoj`被认为是相同的
   - 请**不要再`OJ`中输入空格**，如`Code Forces`
   - 所有可以被识别的`OJ`如表格所示

     | input|OnlineJudge|
     |:---:|:---------:|
     | BZOJ | BZOJ |
     | HDU | HDU |
     | CC/CodeChef | CodeChef |
     | CF/CodeForces | CodeForces |
     | lg/luogu |洛谷|
     |Tsinsen/qingcheng/qc|青橙|
     |POJ|POJ|
     |UOJ/UniversalOnlineJudge|UOJ|
     |LOJ/LibreOJ|LOJ|
     |SPOJ/SphereOnlineJudge|SPOJ|
     |51Nod|51Nod|
     |Ural|Ural|
     |Gym|Gym|

1. `ProblemID`的正确输入方式
   - 对于只用数字作为`ProblemID`的`OJ`(`BZOJ`,`HDU`,`POJ`,`51Nod`,`URAL`)，直接输入数字。
   - 对于`UOJ`,`LOJ`,`洛谷`,`青橙`，`#`,`P`,`A`输入或不输入无所谓。(也就是说`UOJ #233`和`UOJ 233`被认为是相同的)
   - 对于`CodeForces`和`Gym`，输入格式同`666A`。
   - 对于`CodeChef`，请输入`Problem Code`后面的那一串字母。
   - 对于`SPOJ`，虽然`SPOJ`的题目有编号，但是并不能通过编号访问，所以**不能通过输入`SPOJ 8222`来获取链接**，你应该输入的`ProblemID`是下图被框住的那一部分![qwq](http://images.cnblogs.com/cnblogs_com/NuclearSubmarines/1013327/o_SPOJ.png)


## 输出格式

如果输入中有多个`OJ`，将会按照每个`OJ`题目数量的降序输出。

输出的每个OJ的题目都会先排序后输出，排序的第一关键字是`ProblemID`的长度，第二关键字是字典序。

大概是这个样子

| OnlineJudge: CodeForces | Status(0/3) |
| :-------------- | :----: |
| [23D](http://codeforces.com/problemset/problem/23/D) | N/A |
| [67E](http://codeforces.com/problemset/problem/67/E) | N/A |
| [295B](http://codeforces.com/problemset/problem/295/B) | N/A |
