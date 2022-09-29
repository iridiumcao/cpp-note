# 附录一 环境及编译

## 编译运行 C 代码

```bash
$ gcc hello.c -o hello
$ ./hello
```

以上两行指令也可以合写为一行：

```bash
$ gcc hello.c -o hello && ./hello
```

如果不写 `-o` 参数，编译后将自动生成名为 `a.out` 的可执行文件。

```bash
$ gcc hello.c
$ ./a.out
```

## 编译运行 C++ 代码

```bash
$ g++ hello.cpp -o hello
$ ./hello
```

如果不写 `-o` 参数，编译后将自动生成名为 `a.out` 的可执行文件。

```bash
$ g++ hello.cpp
$ ./a.out
```

## 格式化代码

### Visual Studio Code

首先系统要安装有 [clang-format](http://www.codepool.biz/vscode-format-c-code-windows-linux.html)，然后再给 VSCode 安装 clang-format 插件，插件安装好後，可以使用 `Ctrl+Shift+I` 执行格式化代码操作。

