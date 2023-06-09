#! https://zhuanlan.zhihu.com/p/627480972
网络层
---
# 网络层 IPv4,IPv6

- [网络层 IPv4,IPv6](#网络层-ipv4ipv6)
  - [IPv4 分组](#ipv4-分组)
    - [IPv4 分组的格式](#ipv4-分组的格式)
  - [IPv4地址与NAT](#ipv4地址与nat)
    - [IPv4 地址](#ipv4-地址)
    - [网络地址转换](#网络地址转换)
    - [子网划分与子网掩码，CIDR](#子网划分与子网掩码cidr)
  - [ARP,DHCP,ICMP](#arpdhcpicmp)
    - [IP地址与硬件地址](#ip地址与硬件地址)
    - [地址解析协议 ARP](#地址解析协议-arp)
    - [动态主机配置协议 DHCP](#动态主机配置协议-dhcp)
    - [网际控制报文协议 ICMP](#网际控制报文协议-icmp)
- [IPv6](#ipv6)
  - [主要特点](#主要特点)
  - [IPv6 地址](#ipv6-地址)
  - [网络层](#网络层-1)


## IPv4 分组

IP协议定义数据传送的基本单元－－IP分组及其确切的数据格式。   
IP协议也包括一套规则，指明分组如何处理，错误怎样控制。   

### IPv4 分组的格式

一个 IP 分组有首部和数据部分组成。    
**首部**：   
1. 版本
2. 首部长度
3. 总长度
4. 标识
5. 标志
6. 片偏移
7. 生存时间
8. 协议
9. 首部校验和
10. 源地址字段
11. 目的地址字段

**IP 数据报分片**   
一个链路层数据报所能承载的最大数据量称为**最大传送单元**。   
当一个 IP 数据报的总长度大于链路 MTU 时，就需要将 IP 数据报中的数据分装在多个较小的 IP 数据报里。   
目的主机使用 IP 首部中的标识，标志和片偏移字段来完成对片的重组。  
```
DF == 0 可以分片
MF == 1 后面还有片
MF == 1 是最后一个
```

## IPv4地址与NAT 

### IPv4 地址
由网络号与主机号组成。   
$$
IP 地址::＝｛<网络号>, <网络号>｝
$$
主机号全为0表示本网络本身。  
全为1表示本网络的广播地址。  
127.x.x.x 保留为环回自检地址，表示任意主机自身。   
0.0.0.0 表示本网络的本主机。   
255.255.255.255 表示整个TCP/IP网络的广播地址，受限广播地址。   
```
A 类
0 1 2 3     8   16    26    32
| |   网络号  |     主机号     |
B 类
0 1 2 3     8   16    24    32
|10|   网络号     |   主机号     |
C 类
|110|   网络号         | 主机号 |
D 类  多播地址
E 类  保留今后使用
```

### 网络地址转换

网络地址转换（ NAT ）是指通过将专用网络地址（如 Intranet ）转换为共用地址，从而对外隐藏内部管理的 IP 地址。  
**节省了IP 地址的消耗，降低了内部网络受到攻击的危险。**   
私有 IP 地址只用于LAN；可重用；
NAT转换表保存了{本地IP：端口}到{全球IP地址：端口}的映射。

### 子网划分与子网掩码，CIDR
- **子网划分**   
两级IP地址的缺点：IP地址空间利用率有时很低，给每个物理网络分配一个网络号会使路由表变得太大而使网络性能变坏；两级的 IP 地址不够灵活。   
三级IP 地址：
$$
IP地址 ＝ {<网络号>, <子网号>, <主机号>}
$$
- **子网掩码**   
它是一种用来指明一个IP地址的哪些位标识的是主机所在的网络地址以及哪些位标识的是主机地址的位掩码。   
通常情况下，子网掩码的表示方法和地址本身的表示方法是一样的。在IPv4中，就是点分十进制四组表示法（四个取值从0到255的数字由点隔开，比如255.128.0.0）或表示为一个八位十六进制数（如FF.80.00.00，它等同于255.128.0.0），后者用得较少。  
- **无分类址CIDR**   
[CIDR](https://zhuanlan.zhihu.com/p/369707004)  
- **网络层转发分组的过程**    
[网络层转发分组的过程](https://www.cnblogs.com/cone/p/14906428.html)   

## ARP,DHCP,ICMP
### IP地址与硬件地址
IP 地址是网络层使用的地址，它是分层次等级的。  
硬件地址是数据链路层使用的地址MAC，它是平面式的。  
### 地址解析协议 ARP
[ARP](https://zh.wikipedia.org/wiki/%E5%9C%B0%E5%9D%80%E8%A7%A3%E6%9E%90%E5%8D%8F%E8%AE%AE)  
### 动态主机配置协议 DHCP
[DHCP](https://zh.wikipedia.org/wiki/%E5%8A%A8%E6%80%81%E4%B8%BB%E6%9C%BA%E8%AE%BE%E7%BD%AE%E5%8D%8F%E8%AE%AE)  
### 网际控制报文协议 ICMP
[ICMP](https://zh.wikipedia.org/wiki/%E4%BA%92%E8%81%94%E7%BD%91%E6%8E%A7%E5%88%B6%E6%B6%88%E6%81%AF%E5%8D%8F%E8%AE%AE)  

# IPv6
## 主要特点
4.4.1 IPv6的主要特点

解决“IP地址耗尽”问题的措施有以下三种：
1. 采用无类别编址 CIDR,使IP地址的分配更加合理
2. 采用网络地址转换(NAT)方法以节省全球IP地址;
3. 采用具有更大地址空间的新版本的IPv6. 其中前两种方法只是延长了IPv4地址分配完毕的时间,只有第三种方法从根本上解 决了IP地址的耗尽问题。  

更大的地址空间。IPv6将地址从IPv4 的32 位增大到了128位,IPv6的字节数(16B)是IPv4字节数(4B)的平方。  
IPv6 只有在包的结点才能分片,是端到端的,传输路径中的路由器不能分片,所以从 一般意义上说,IPv6不允许分片(不允许类似IPv4的路由分片)。  
IPv6首部长度必须是8B的整数倍,而IPv4首部是4B的整数倍。  
简化了IP分组头,它包含8个域(IPv4是12个域)。这一改变使得路由器能够更快地处 理分组,从而可以改善吞吐率。  
## IPv6 地址
[IPv6](https://www.ibm.com/docs/zh/i/7.2?topic=concepts-ipv6-address-formats)  
IPv6 地址大小为 128 位。首选 IPv6 地址表示法为 x:x:x:x:x:x:x:x，其中每个 x 是地址的 8 个 16 位部分的十六进制值。IPv6 地址范围从 0000:0000:0000:0000:0000:0000:0000:0000 至 ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff。

**省略前导零**    
通过省略前导零指定 IPv6 地址。例如，IPv6 地址 1050:0000:0000:0000:0005:0600:300c:326b 可写作 1050:0:0:0:5:600:300c:326b。  
**双冒号**  
通过使用双冒号（::）替换一系列零来指定 IPv6 地址。例如，IPv6 地址 ff06:0:0:0:0:0:0:c3 可写作 ff06::c3。一个 IP 地址中只可使用一次双冒号。
IPv6 地址的替代格式组合了冒号与点分表示法，因此可将 IPv4 地址嵌入到 IPv6 地址中。对最左边 96 个位指定十六进制值，对最右边 32 个位指定十进制值，来指示嵌入的 IPv4 地址。在混合的网络环境中工作时，此格式确保 IPv6 节点和 IPv4 节点之间的兼容性。  

网络层
---