#include "ros/ros.h"
#include "beginner_tutorial/MsgTutorial.h" //MsgTutorial 메세지 파일 페더(빌드 후 자동생성)

// 메세지 콜백함수로서, 아래서 설정한 "ros_tutorial_msg" 토픽, 메세지를 수신했을 때 동작하는 함수
// 입력 메세지로는 beginner_tutorial 패키지의 MsgTutorial 메세지를 받도록 되어있음
// ConstPtr& msg의 주소값을 갖고오겠다는 뜻 
void msgCallback(const beginner_tutorial::MsgTutorial::ConstPtr& msg)
{
	ROS_INFO("recievemsg=%d", msg -> stamp.sec);
	ROS_INFO("recievemsg=%d", msg -> stamp.nsec);
	ROS_INFO("recievemsg=%d", msg -> data);
	
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "topic_subscriber"); // 노드명 초기화
	ros::NodeHandle nh; // ROS 시스템과 통신을 위한 노드핸들 선언
	
	// subscribe 선언, "beginner_tutorial" 
        // 패키지의 MsgTutorial 메세지 파일을 이용한
	// subscriber ros_tutorial_sub를 작성한다.
	// 토픽명은 ros_tutorial_msg 이며 Queue 사이즈를 100개로 설정한다 
	ros::Subscriber ros_tutorial_sub=nh.subscribe("ros_tutorial_msg", 100, msgCallback); 	// ros_tutorial_msg 라는 구독 정보를 마스터에게 보낸다

	// 콜백함수 호출을 위한 함수로 메세지가 수신되기를 대기, 수신되었을 경우 콜백함수 실행
	ros::spin();
	return 0;

}

