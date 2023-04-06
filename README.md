# join_message插件仓库
将join_message.dll文件丢到plugins目录下即可.

## 游戏内使用方法:
输入指令 /jm 即可调出插件图形界面.

## 更多信息请移步:
- 插件源码仓库([点此跳转](https://github.com/LymoProjects/joinMessage))
- 插件齿包页面([点此跳转](https://registry.litebds.com/#/join_message))

## 作为依赖进行二次开发
- 在服务器运行你的插件之前, 你需要让join_message.dll(前置插件)存在于plugins目录下.
- 在你的项目中引入include目录下的头文件并静态链接lib目录下的join_message.lib.
- 将你编译完成的插件同样放入plugins文件夹下(或者通过齿包安装到服务器中)即可!
