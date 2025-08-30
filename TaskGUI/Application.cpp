#include "Application.h"
#include "imgui/imgui.h"
#include "imgui/imgui_stdlib.h"
#include <string>
#include <vector>

struct task{
	std::string taskName;
	bool taskStatus = false;
};

std::vector<task> tasks;
std::string placeholder = "";

namespace Tasking{

	void RenderUI(){
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
	ImGui::Begin("Tasks", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
	ImGui::SetNextItemWidth(300);
	ImGui::InputText(" ", &placeholder);
	ImGui::SameLine();
	if(ImGui::Button("Add Task")){
		tasks.push_back({placeholder});
		placeholder.clear();
	}
	for(size_t i = 0; i < tasks.size(); i++){
		ImGui::Text("%s", tasks[i].taskName.c_str());
		ImGui::SameLine();
		if(ImGui::Button(("Remove##" + std::to_string(i)).c_str())){
			tasks.erase(tasks.begin() + i);
		}
	}
	ImGui::End();

	}

}
