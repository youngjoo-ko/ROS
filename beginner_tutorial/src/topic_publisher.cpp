#include "ros/ros.h" // ROS 기본 헤더파일
#include "beginner_tutorial/MsgTutorial.h" //MsdTutorial 메세지 파일의 헤더(빌드 후 자동생성 됨)

int main(int argc, char **argv) // 노드 메인함수
{
	ros::init(argc, argv, "topic_publisher"); // 노드명 초기화
	ros::NodeHandle nh; // ROS 시스템과 통신을 위한 노드 핸들 선언(노드식별을 위한 핸들)
	// 퍼블리셔 선언, "  "패키지의 MsgTutorial.msg 파일을 이용한 퍼블리셔 "ros_tutorial_pub "(노드)을 작성한다.
	ros::Publisher ros_tutorial_pub=nh.advertise<beginner_tutorial::MsgTutorial>("ros_tutorial_msg",100);
	// 노드핸들(nh)를 통해 퍼블리셔노드가 토픽 광고한다 
	// 토픽명은 "ros_tutorial_msg"이며, 퍼블리셔 큐(queue) 사이즈를 100개로 설정한다

	ros::Rate loop_rate(10); //루프주기를 설정 "10"이라는 것은 10Hz를 의미, 0.1초 마다 반복
	beginner_tutorial::MsgTutorial msg; //MsgTutorial 메세지 파일 형식으로 msg라는 메세지 선언
	int count=0; // 사용될 변수 선언
	
	while(ros::ok()){
		msg.stamp = ros::Time::now(); // 현재시간을 msg의 하위 stamp 메세지에 담는다 
		msg.data = count; //count라는 변수값을 msg의 하위 data에 담는다
		// 디버깅을 위한 확인 (print) 
		ROS_INFO("send msg=%d", msg.stamp.sec); // stamp.sec 메세지를 표시
		ROS_INFO("send msg=%d", msg.stamp.nsec); // stamp.nsec 메세지를 표시
		ROS_INFO("send msg=%d", msg.data); // 메세지 표시
		ros_tutorial_pub.publish(msg); // 메세지 발행
		loop_rate.sleep(); // 위에서 정한 루프 주기를 맞추기 위해 sleep에 들어감 
		++count; // count 변수 1씩 증가 
	}
	return 0;
}

