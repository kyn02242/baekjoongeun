# [Silver II] 오목 - 2072 

[문제 링크](https://www.acmicpc.net/problem/2072) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현, 시뮬레이션

### 제출 일자

2024년 11월 16일 02:33:25

### 문제 설명

<p style="text-align: center;"><img alt="" height="402" src="https://www.acmicpc.net/JudgeOnline/upload/201007/5m.png" width="400"></p>

<p>19x19크기의 바둑판에, 돌을 놓을 좌표가 주어지면 이 게임이 몇 수만에 끝나는 지를 알아보려고 한다. 사용하고자 하는 바둑판의 모양은 위의 그림과 같으며, (1, 1)이 가장 왼쪽 위의 좌표이고 (19, 19)가 가장 오른쪽 아래의 좌표이다. 오목은 흑 또는 백이 5개의 돌을 가로, 세로, 혹은 대각선으로 연속으로 놓았을 경우 게임이 끝나게 된다. 즉, 다음 그림과 같은 경우를 말한다.</p>

<p style="text-align: center;"><img alt="" height="272" src="https://www.acmicpc.net/JudgeOnline/upload/201007/5mm.png" width="402"></p>

<p>게임은 흑이 먼저 시작하며, 한수씩 서로 번갈아 가며 두게 된다. 다음 좌표들과 같이 차례로 돌을 놓으며 게임을 진행한다고 하자. (홀수번째는 흑, 짝수번째는 백)</p>

<ul>
	<li>1 - (3,3)</li>
	<li>2 - (2,3)</li>
	<li>3 - (3,4)</li>
	<li>4 -  (2,2)</li>
	<li>5 - (3,2)</li>
	<li>6 - (3,1)</li>
	<li>7 - (3,5)</li>
	<li>8 - (2,4)</li>
	<li>9 - (2,5)</li>
	<li>10 - (2,1)</li>
	<li>11 - (1,5)</li>
	<li>12 - (4,1)</li>
	<li>13 - (4,5)</li>
	<li>14 - (5,5)</li>
	<li>15 - (1,4)</li>
	<li>16 - (5,1)</li>
	<li>17 - (1,3)</li>
	<li>18 - (1,1)</li>
	<li>19 - (5,3)</li>
	<li>20 - (5,2)</li>
	<li>21 - (1,2)</li>
	<li>22 - (5,4)</li>
	<li>23 - (4,2)</li>
	<li>24 - (4,4)</li>
	<li>25 - (4,3)</li>
</ul>

<p>위의 순서대로 바둑판에 돌을 놓으면 아래의 왼쪽 그림과 같이 된다.</p>

<p style="text-align: center;"><img alt="" height="129" src="https://www.acmicpc.net/JudgeOnline/upload/201007/5mmm.png" width="129"><img alt="" height="130" src="https://www.acmicpc.net/JudgeOnline/upload/201007/5m2.png" width="128"></p>

<p>그런데 생각해보면, 위의 좌표대로 돌을 놓았을 때 오른쪽 그림처럼 18번째의 돌을 놓는 것으로서 게임이 끝나 버리는 것을 알 수 있다. 이 경우, 답은 18이다.</p>

<p>바둑판에 돌을 놓는 좌표가 입력될 때, 몇 번째 수에서 오목이 끝나는지를 찾는 프로그램을 작성하시오. 오목을 두다 보면 다음과 같이 돌이 5개를 거치지 않고 6개 이상의 돌이 나란히 놓이는 경우가 발생할 수 있다. 이런 경우에는 승리를 인정하지 않고 오목이 계속된다는 것에 주의하라.</p>

<p style="text-align: center;"><img alt="" height="109" src="https://www.acmicpc.net/JudgeOnline/upload/201007/5m5.png" width="169"></p>

### 입력 

 <p>첫째 줄에 바둑판에 놓이는 돌의 개수 N(1 ≤ N ≤ 100)이 주어진다. 그 다음 N줄에는 놓이는 돌의 좌표들이 차례로 주어진다. (홀수번째는 흑, 짝수번째는 백) 돌을 놓은 곳에 또 돌을 놓는 경우는 없다.</p>

### 출력 

 <p>첫째 줄에 몇 번째 수에서 승패가 갈리는지를 출력한다. 승패가 갈리지 않는 경우에는 -1을 출력한다.</p>

