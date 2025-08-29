#include "Application.h"
#include "imgui/imgui.h"
#include <string>

struct Task{
	std::string taskName;
	bool taskStatus;
};

Task myTask{"Testing1", false};

namespace Tasking{

	void RenderUI(){

	ImGui::Begin("Tasks");
	ImGui::Button("Halp");
	ImGui::Text("%s", myTask.taskName.c_str());
	ImGui::End();

	}

}
