# traffic light

> 本项目是基于Qt的，基于S3C2440嵌入式开发实验平台的模拟交通信号灯控制系统。
>
> 本项目涉及到的硬件有：S3C2440嵌入式开发实验平台（包括触摸屏、LED灯和七段数码管）、USB摄像头、RFID及IC卡。

## 编译和使用说明

### 编译环境要求

- Linux 操作系统
- Qt-for-embedded (Qt4)

### 编译操作

1. 首先，加载到项目所在路径。

2. 接着，输入下列命令编译出二进制可执行文件app。

```bash
$> qmake
$> make
```

### 使用说明

1. 连接RFID模块、USB摄像头模块到嵌入式开发实验平台。
2. 连接xshell到嵌入式开发试验平台。
3. 使用xshell操作嵌入式开发实验平台加载s3c2440-led.ko驱动。

```bash
$> insmod s3c2440-led.ko
```

4. 需首先执行嵌入式开发试验平台上附带ts_calibrate程序，生成ts.conf文件，以校准嵌入式开发实验平台触摸屏。
5. 使用xshell挂载项目目录到嵌入式开发实验平台/mnt/nfs目录下。
6. 使用xshell，加载到项目文件夹，即编译出的二进制文件的所在路径下。
7. 执行程序

```bash
$> ./app -qws -font unifont
```

8. 点击触摸屏上的Unlock按钮，接着刷IC卡，以解锁用户的使用权限。
9. 点击switch to manual按钮可以切换到手动模式，此时switch light按钮解锁，可通过点击该按钮切换交通灯状态。
10. 点击switch to auto按钮可以重新恢复到自动状态，交通灯变化自动控制。
11. 点击open camera按钮可以使用v4l开启USB摄像头，将摄像头画面展示到触摸屏上。
12. 再次点击open camera按钮，可以释放v4l，关闭USB摄像头。

