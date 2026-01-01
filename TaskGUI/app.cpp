#include "app.h"
#include "imgui/imgui.h"
#include "imgui/imgui_stdlib.h"
#include <string>
#include <vector>

struct task{
	std::string taskName;
	bool taskStatus = false;
};

std::vector<task> tasks;
std::string textInput = "";
ImGuiInputTextFlags flags = ImGuiInputTextFlags_EnterReturnsTrue;

void addTask(){
	tasks.push_back({textInput});
	textInput.clear();
}

namespace Tasking{

	void RenderUI(){
		ImGui::SetNextWindowPos(ImVec2(0, 0));
		ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
		ImGui::Begin("Tasks", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);
		ImGui::SetNextItemWidth(300);
		if(ImGui::InputTextWithHint("##Task Name", "Task Name...", &textInput, flags) && textInput.length() != 0){
			tasks.push_back({textInput});
			textInput.clear();
		}
		ImGui::SameLine();
		if(ImGui::Button("Add Task")){
			if(textInput.length() != 0){
				tasks.push_back({textInput});
				textInput.clear();
			}
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
