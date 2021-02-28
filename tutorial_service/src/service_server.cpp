
#include "ros/ros.h"
#include "tutorial_service/srv_tutorial.h" 

bool calculation(tutorial_service::srv_tutorial::Request &req, tutorial_service::srv_tutorial::Response &res)
{
	res.result = req.a + req.b;
	ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
	ROS_INFO("sending back response:%ld", (long int)res.result);
		
	return true;
}

// tutorial_service::srv_tutorial::Request &req : 튜토리얼서비스 패키지의 서브튜토리얼 서비스파일을 참조하여 Request 패키지를 쓸거다 서비스파일에서 요청에 필요한 정보만 (a,b)가져와서 req포인터에 넣을것임




int main(int argc, char **argv)
{
	ros::init(argc, argv, "service_server"); 
	ros::NodeHandle nh; 
	 
	ros::ServiceServer server=nh.advertiseService("ros_tutorial_srv", calculation);
	ROS_INFO("ready service server!!");
	ros::spin(); // 수신대기
	return 0;
}


// init : 터미널창에서 명령어 (rosrun tutorial_service service_server) 에서 경로를 argv로 가져와 노드명을 초기화한다 (노드명 service_server)
// ServiceServer : 서비스 서버를 선언한다.(서버명 server)
// nh.advertiseService : (보내는) 서비스명은 ros_tutorial_srv 이고 , 서비스 요청이 있을때 calculation 함수를 실행할 것이다.
// 
