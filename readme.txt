可能有问题的代码：
1、 database.cpp  中很多函数未检测传入的任务代号是否为空，可能会产生键值为空的记录

2、QMessage mess，推荐使用静态方式获取，动态方式可能会产生内存泄露。如
建议使用QMessage mess; 而不是QMessage *mess = new QMessage（）；


解决问题:
	1、出现两个更新状态页面
	2、无法提交更新