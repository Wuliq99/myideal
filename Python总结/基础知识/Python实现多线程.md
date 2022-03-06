# Python实现多线程

**环境**

> python3+Windows11

## 通过标准库实现

python提供的两个线程标准库：

- **_thread**
- **threading(推荐使用)**

tips

thread 模块已被废弃。用户可以使用 threading 模块代替。所以，在 Python3 中不能再使用"thread" 模块。为了兼容性，Python3 将 thread 重命名为 "_thread"。

区别

_thread 提供了低级别的、原始的线程以及一个简单的锁，它相比于 threading 模块的功能还是比较有限的。

threading 模块除了包含 _thread 模块中的所有方法外，还提供的其他方法：

- threading.currentThread(): 返回当前的线程变量。
- threading.enumerate(): 返回一个包含正在运行的线程的list。正在运行指线程启动后、结束前，不包括启动前和终止后的线程。
- threading.activeCount(): 返回正在运行的线程数量，与len(threading.enumerate())有相同的结果。

### _thread

常用函数

函数名

> ```python
> _thread.start_new_thread ( function, args[, kwargs] )
> ```

作用

> 产生新线程

参数:

> - function - 线程函数。
> - args - 传递给线程函数的参数,他必须是个tuple类型。
> - kwargs - 可选参数。

### threading

常用函数

> ``` python
> thread.join( [timeout] )
> ```

作用

> 指定 thread 线程最多可以霸占 CPU 资源的时间（以秒为单位）

参数

> timeout - 设置超时时间，如果省略，则默认直到 thread 执行结束（进入死亡状态）才释放 CPU 资源

注意

> 必须为 threading.Thread 及其子类才可使用 join() 方法







## 线程优先级队列（ Queue）

Python 的 Queue 模块中提供了**同步的、线程安全**的队列类，包括FIFO（先入先出)队列Queue，LIFO（后入先出）队列LifoQueue，和优先级队列 PriorityQueue。

这些队列都实现了锁原语，能够在多线程中直接使用，可以使用队列来实现线程间的同步。

Queue 模块中的常用方法:

> - Queue.qsize() 返回队列的大小
> - Queue.empty() 如果队列为空，返回True,反之False
> - Queue.full() 如果队列满了，返回True,反之False
> - Queue.full 与 maxsize 大小对应
> - ·Queue.get([block[, timeout]])获取队列，timeout等待时间
> - Queue.get_nowait() 相当Queue.get(False)
> - Queue.put(item) 写入队列，timeout等待时间
> - Queue.put_nowait(item) 相当Queue.put(item, False)
> - Queue.task_done() 在完成一项工作之后，Queue.task_done()函数向任务已经完成的队列发送一个信号
> - Queue.join() 实际上意味着等到队列为空，再执行别的操作

待查文章

[Python线程指南 - AstralWind - 博客园 (cnblogs.com)](https://www.cnblogs.com/huxi/archive/2010/06/26/1765808.html)