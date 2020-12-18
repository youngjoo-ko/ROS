#include "ros/ros.h"
#include <sensor_msgs/PointCloud2.h>
#include "visualization_msgs/MarkerArray.h"
#include <sensor_msgs/LaserScan.h>

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


int main(int argc, char **argv) // 노드 메인함수
{
	ros::init(argc, argv, "multi_pub_sub_node"); // 노드명 초기화
	ros::NodeHandle nh; // ROS 시스템과 통신을 위한 노드 핸들 선언(노드식별을 위한 핸들)
	// 퍼블리셔 선언, "  "패키지의 MsgTutorial.msg 파일을 이용한 퍼블리셔 "ros_tutorial_pub "(노드)을 작성한다.
	ros::Publisher multi_pub=nh.advertise<sensor_msgs::PointCloud2>("filtered_cloud",1);

	ros::Subscriber multi_sub_1=nh.subscribe<sensor_msgs::LaserScan>("raw_lidar",100, msgCallback_1);
	ros::Subscriber multi_sub_2=nh.subscribe<visualization_msgs::MarkerArray>("marker_array",100, msgCallback_2);
	// 노드핸들(nh)를 통해 퍼블리셔노드가 토픽 광고한
	// 토픽명은 "ros_tutorial_msg"이며, 퍼블리셔 큐(queue) 사이즈를 100개로 설정한다

	ros::Rate loop_rate(1); //루프주기를 설정 "10"이라는 것은 10Hz를 의미, 0.1초 마다 반복
	sensor_msgs::PointCloud2 point_msg; //MsgTutorial 메세지 파일 형식으로 msg라는 메세지 선언
	
//int count=0; // 사용될 변수 선언
	
	while(ros::ok()){
		
		// 디버깅을 위한 확인 (print) 
		ROS_INFO("send msg=%d", point_msg.height);
		ROS_INFO("send msg=%d", point_msg.width); 
		multi_pub.publish(point_msg); // 메세지 발행
		
		loop_rate.sleep(); // 위에서 정한 루프 주기를 맞추기 위해 sleep에 들어감 
		
	}
	return 0;
}








