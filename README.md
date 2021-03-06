# raspberrypi4
Using raspberry pi 4, practice various module  
  
**object** : 라즈베리파이를 이용한 다양한 모듈 실습  
**model**  : raspberry pi 4 model B, 8GB RAM

~~실습할 때 참고했던 블로그들 출처 남겨놓습니다. 문제시 말씀해주세요.~~  

___
### 0. 라즈베리파이 시작하기  
**0.1 raspbian os 용 메모리카드 만들기**
- supplies : raspberry pi 4(model B 8GB), microSD(32GB), SD Reader, Pi case(option), raspberry pi Heatsink
  
**0.1.1 raspberry pi Imager download**  
  
[Imager Installation](https://www.raspberrypi.com/software/)
  
**0.1.2**  

![0](https://user-images.githubusercontent.com/100012844/159913733-ff9696a0-877f-4ba5-b172-20b1e78771e9.PNG)

- Operating Ststem : raspberry pi OS select
- Storage : Reader 로 연결한 microSD select
- WRITE  이 때 인터넷 연결상태, 컴퓨터 사양에 따라 꽤 오랜 시간이 소요되기도한다.
  
**0.1.3**  
- Heatsink 를 다음과 같은 위치에 붙여준다.  

 ![1](https://user-images.githubusercontent.com/100012844/159917856-ea2891e1-0308-493a-8cb8-45aeeae9e47c.png)

- 0.1.2의 microSD를 raspberry pi 에 삽입한다.
- 사용하려는 모니터, 키보드, 마우스 등 입출력장치를 연결한다.  
위와 같은 입출력장치 없이 원격제어를 사용할 수 있으나 딜레이가 심하게 발생할 수 있다.  
이런 경우 모니터만 연결해도 딜레이를 줄일 수 있다.  
[Raspbreey Pi 4를 VNC로 접속하여 원격 제어하는 방법](https://webnautes.tistory.com/549?category=759152)  

**0.1.4**  
- 다음의 블로그를 참고하여 raspbian OS 사용을 위한 설정을 완료한다.  
[Raspberry Pi 4 처음 사용하기](https://webnautes.tistory.com/899?category=759152)  

```
sudo raspi-config
```
System Options - Password,  Location Options - Timezone,  Interface Options etc.

### 1. Python 및 C language 개발 환경 만들기
  
**1.1** 개발환경 최신화 시키기  
- raspberry pi [terminal] click  
```Linux
sudo apt update
sudo apt upgrade
```

**1.2** Python IDE 개발환경 만들기
  
[[3회차-4] 라즈베리파이 GPIO 실습-1](https://aisw.tistory.com/21)  

```
sudo apt install python-rpi.gpio python3-rpi.gpio
```

**1.3** C언어 개발환경 만들기
[라즈베리파이 GPIO 사용하기 - git gitcore(wiringPi 다운에러)](https://infinitt.tistory.com/20)  

**1.3.1** C 언어 사용을 위한 wiringPi library install

```
sudo apt install git-core
git clone https:// github.com/WringPi/WringPi
cd WringPi
./ build
```

**1.3.2** 설치확인

```
gpio -v
gpio readall
```

**1.3.3** 예제파일 다운로드 및 실행

```
git clone http://github.com/eleparts/raspi-LearningKit
cd raspi-LearningKit/
ls -l
```

## C language example code
[eleparts-raspiLearningKit](https://github.com/eleparts/raspi-LearningKit)  
  
C언어 예제는 위 링크의 예제 코드를 이용하여 공부하고  
그 외의 참고 코드들은 각 file의 README에 출처를 첨부한다. 

## Python language example code
  
파이썬으로 작성된 코드의 참조된 출처는 각 file의 README에 첨부한다.  

___

#### 필기자료
라즈베리파이1주차.pdf 파일은 제가 공부한 내용인데, 정확도는 떨어질 수 있으니 참고만해주세요!  
잘못된 내용있다면 알려주시면 감사하겠습니다.
