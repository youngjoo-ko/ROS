#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include "visualization_msgs/MarkerArray.h"
#include "geometry_msgs/Point.h"

#include "object_detection.h"


void msgCallback_1(const sensor_msgs::LaserScan::ConstPtr& msg)
{
	ROS_INFO("recieve_msg=%d", msg -> angle_min);
  	ROS_INFO("recieve_msg=%d", msg -> angle_max);
	ROS_INFO("recieve_msg=%d", msg -> angle_increment);
}


void msgCallback_2(const visualization_msgs::MarkerArray::ConstPtr& msg)
{
	ROS_INFO("recieve_msg=%d", msg -> markers);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "object_detection_sub_node"); // 노드명 초기화
	ros::NodeHandle nh; // ROS 시스템과 통신을 위한 노드핸들 선언
	
	// subscriber 선언, "beginner_tutorial" 
           // 패키지의 MsgTtutorial 메세지 파일을 이용한
	// subscriber ros_tutorial_sub를 작성한다.
	// 토픽명은 ros_tutorial_msg 이며 Queue 사이즈를 100개로 설정한다 
	ros::Subscriber detection_sub1=nh.subscribe("raw_lidar", 100, msgCallback_1);
	ros::Subscriber detection_sub2=nh.subscribe("marker_array", 100, msgCallback_2); 	// ros_tutorial_msg 라는 구독 정보를 마스터에게 보낸다

	// 콜백함수 호출을 위한 함수로 메세지가 수신되기를 대기, 수신되었을 경우 콜백함수 실행
	ros::spin();
	return 0;

}

