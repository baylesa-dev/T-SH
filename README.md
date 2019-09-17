<p align="center">
    <img src="https://secure.wphackedhelp.com/blog/wp-content/uploads/2018/10/examples-web-shell.gif" width=800>
    <h1 align="center">T-SH</h1>
    <h2 align="center">Unix Shell - man tcsh</h2>
</p>

- <a href="#description">Description</a>
- <a href="#installation">Installation</a>
  - <a href="#prerequisites">Prerequisites</a>
  - <a href="#compilation">Compilation</a>

---

## Description

This project is the rewrite of a Unix shell, in C with [libC](http://man7.org/linux/man-pages/man7/libc.7.html).

It displays a prompt, parse and execute some commands.

#### Parsing and execution

- **This shell can handle:**
  - space and tabs (multiples, errors, ...)
  - `$PATH` and environment
  - errors and return value
  - redirections (`<`, `>`, `<<` and `>>`)
  - pipes (`|`)
  - builtins: `cd`, `echo`, `exit`, `setenv`, `unsetenv`
  - separators: `;`, `&&`, `||`

For instance, you should be able to execute the following command:

```
➜ ./t-sh

t-sh> cd ; </etc/hosts od -c | grep xx | wc >> /tmp/z -l ; cd - && echo "OK"
```

> You can move throught you shell line with your arrow keys. ✨

> There is also an command history ! Find it with up and down arrow keys. ✨✨

---

## Installation

### Prerequisites

> 🚨 **This program only work on Unix based operating systems.** 🚨

**Install essentials build tools:**

```
sudo apt install build-essential
```

### Compilation

**Clone repository:**

```
git clone https://github.com/baylesa-dev/T-SH.git && cd T-SH
```

**Compile sources:**

```
make
```

**Execute:**

```
./t-sh
```
