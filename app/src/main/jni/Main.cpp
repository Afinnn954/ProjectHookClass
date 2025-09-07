#include <iostream>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <stdint.h>
#include <inttypes.h>
#include <vector>
#include <map>
#include <chrono>
#include <fstream>
#include <thread>
#include <pthread.h>
#include <dirent.h>
#include <libgen.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <jni.h>
#include <android/log.h>
#include <elf.h>
#include <dlfcn.h>
#include <sys/system_properties.h>
#include <EGL/egl.h>
#include <GLES3/gl3.h>

#include "imgui.h"
#include "imgui_additional.h"
#include "backends/imgui_impl_android.h"
#include "backends/imgui_impl_opengl3.h"
#include "android_native_app_glue.h"
#include "fonts/GoogleSans.h"
#include "Icon.h"
#include "Iconcpp.h"

#include "struct/Vector3.hpp"
#include "struct/Vector2.h"
#include "struct/Color.h"
#include "struct/Rect.h"
#include "struct/Quaternion.h"
#include "struct/MonoString.h"

#include "unity/fake_dlfcn.h"
#include "unity/Il2Cpp.h"
#include "unity/Tools.h"
#include "unity/Unity.h"

#include "config/Setup.h"

#include "feature/GameClass.h"
#include "feature/ToString.h"
#include "feature/RoomInfo.h"
#include "feature/DrawESP.h"
#include "feature/AutoAim.h"
#include "Tools/Jni_Stuff.h"
#include "Tools/ImGuiStuff.h"


bool show_another_kontol = false;

bool show_another_esp = false;

bool show_another_window = true;
bool show_items_window = false;
bool show_aimbot_window = false;
bool show_memory_window = false;
    
EGLBoolean (*orig_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean _eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
	
	eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
	eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
	
	if (glWidth <= 0 || glHeight <= 0) {
		return eglSwapBuffers(dpy, surface);
	}
    
    if (!g_Initialized) {
          ImGui::CreateContext();
        ImGuiStyle *style = &ImGui::GetStyle();
                   
     style->FramePadding = ImVec2(4, 2);
    style->ItemSpacing = ImVec2(10, 2);
    style->IndentSpacing = 12;
    style->ScrollbarSize = 10;

    style->WindowRounding = 4;
    style->FrameRounding = 4;
    style->PopupRounding = 4;
    style->ScrollbarRounding = 6;
    style->GrabRounding = 4;
    style->TabRounding = 4;
    

		style->Colors[ImGuiCol_Text]                  = ImColor(255, 255, 0, 255);
        style->Colors[ImGuiCol_WindowBg]              = ImColor(0, 0, 0, 100);
        style->Colors[ImGuiCol_Border]                = ImColor(28, 28, 28, 255);
        style->Colors[ImGuiCol_FrameBg]               = ImColor(255, 255, 255, 100);
        style->Colors[ImGuiCol_FrameBgActive]               = ImColor(28, 28, 28, 255);
        style->Colors[ImGuiCol_FrameBgHovered]               = ImColor(28, 28, 28, 255);
        style->Colors[ImGuiCol_Button]               = ImColor(255, 0, 0, 80);
        style->Colors[ImGuiCol_ButtonActive]               = ImColor(255, 0, 0, 80);
        style->Colors[ImGuiCol_ButtonHovered]               = ImColor(255, 0, 0, 80);
        style->Colors[ImGuiCol_PopupBg]               = ImColor(255, 0, 0, 80);
        style->Colors[ImGuiCol_MenuBarBg]             = ImColor(255, 0, 0, 80);
        style->Colors[ImGuiCol_Tab] = ImColor(255, 0, 0, 80);
        style->Colors[ImGuiCol_TabActive] = ImColor(255, 0, 0, 80);
        style->Colors[ImGuiCol_TabHovered] = ImColor(255, 0, 0, 80);
        style->Colors[ImGuiCol_TitleBg]               = ImColor(255, 0, 0, 80);
        style->Colors[ImGuiCol_TitleBgActive]         = ImColor(255, 0, 0, 80);
        style->Colors[ImGuiCol_TitleBgCollapsed]      = ImColor(255, 0, 0, 80);
        style->Colors[ImGuiCol_Header]                = ImColor(255, 0, 0, 80);
        style->Colors[ImGuiCol_HeaderActive]          = ImColor(255, 0, 0, 80);
        style->Colors[ImGuiCol_HeaderHovered]         = ImColor(255, 0, 0, 80);
        style->Colors[ImGuiCol_CheckMark]             = ImColor(255, 0, 0, 80);

        ImGuiIO* io = &ImGui::GetIO();
        io->IniFilename = nullptr;

        ImGui_ImplAndroid_Init();
        ImGui_ImplOpenGL3_Init("#version 300 es");

        ImFontConfig font_cfg;
        io->Fonts->AddFontFromMemoryCompressedTTF(GoogleSans_compressed_data, GoogleSans_compressed_size, 25.0f/*(float) get_dpi() / 14.0f*/, &font_cfg);

        g_Initialized = true;
    }

    ImGuiIO* io = &ImGui::GetIO();

    /*get touch from unity game*/
  //  ImGui_GetTouch(io, get_height());

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(get_width(), get_height());
    ImGui::NewFrame();

    DrawESP(ImGui::GetBackgroundDrawList(), get_width(), get_height(), get_dpi());    

    ImGui::SetNextWindowSize(ImVec2((float) get_width() * 0.50f, (float) get_height() * 0.88f), ImGuiCond_Once);
   // if (show_another_window) {
		if (ImGui::Begin(OBFUSCATE("FADLI MOD VIP" ), 0, ImGuiWindowFlags_NoBringToFrontOnFocus)) {
         
static bool FWalidAntiCrack = "t";
static bool FWalidAntiCrack2 = "r";
static bool FWalidAntiCrack3 = "u";
static bool FWalidAntiCrack4 = "e";
static bool isLogin, logginIn = FWalidAntiCrack+FWalidAntiCrack2+FWalidAntiCrack3+FWalidAntiCrack4;
		static std::string err;
		if (!isLogin) {
			ImGui::Text(OBFUSCATE("Input License;"));
								
			ImGui::PushItemWidth(-1);
			static char s[150];
			ImGui::InputText("##key", s, sizeof s);
			
			ImGui::PopItemWidth();
			ImGui::PushItemWidth(-1);
			if (ImGui::Button(OBFUSCATE("Paste License"), ImVec2(ImGui::GetWindowContentRegionWidth(), 0))) {
				auto key = getClipboard();
				strncpy(s, key.c_str(), sizeof s);
			}
			ImGui::PopItemWidth();
			
			ImGui::PushItemWidth(-1);
			
			if (ImGui::Button(OBFUSCATE("Login"), ImVec2(ImGui::GetWindowContentRegionWidth(), 0))) {
				err = Login(s);
				if (err == "OK") {
					isLogin = bValid && g_Auth == g_Token;
				}
			}
            ImGui::PopItemWidth();
			
			if (!err.empty() && err != std::string(OBFUSCATE("OK"))) {
				ImGui::Text(OBFUSCATE("Free Mod"), err.c_str());
				
			}
			ImGui::PopItemWidth();
		
            } else {           
            
        if(ImGui::BeginTabBar("Tab", ImGuiTabBarFlags_FittingPolicyScroll)) {
            
            if (ImGui::BeginTabItem("Menu ESP")) {
				show_another_esp = false;
				show_another_kontol = false;
				
           
                ImGui::BeginGroupPanel(" ", ImVec2(0.0f, 0.0f));
				
                ImGuiIO io = ImGui::GetIO();
                ImGui::Text( "FPS: %.2f", 1000 / io.Framerate );
                ImGui::BeginGroupPanel("ESP", ImVec2(0.0f, 0.0f));      
                ImGui::Checkbox("ESP Line", &Config.ESP.Player.Line);
                ImGui::Checkbox("ESP Box", &Config.ESP.Player.Box);
                ImGui::Checkbox("ESP Health", &Config.ESP.Player.Health);
                ImGui::Checkbox("ESP Name", &Config.ESP.Player.Name);
                ImGui::Checkbox("ESP Distance", &Config.ESP.Player.Distance);
                ImGui::Checkbox("ESP Hero", &Config.ESP.Player.Hero);
              ImGui::Checkbox("ESP CoolDown", &Config.ESP.Player.CoolDown);
               ImGui::Checkbox("ESP Alert", &Config.ESP.Player.Alert);
                ImGui::Checkbox("Visible Check", &Config.ESP.Player.Visible);
                ImGui::Spacing();
                ImGui::EndGroupPanel();                                
                ImGui::SameLine();
                ImGui::BeginGroupPanel("Monster ESP", ImVec2(0.0f, 0.0f));
                ImGui::Checkbox("Monster Box", &Config.ESP.Monster.Box);
                ImGui::Checkbox("Monster Health", &Config.ESP.Monster.Health);
                ImGui::Checkbox("Monster Name", &Config.ESP.Monster.Name);
                ImGui::Checkbox("Monster Alert", &Config.ESP.Monster.Alert);
                ImGui::Spacing();
                ImGui::EndGroupPanel();     				
				ImGui::BeginGroupPanel("Colors", ImVec2(0.0f, 0.0f));
				       ImGui::Text("Choose Themes");
                   static int e = -1;
                   ImGui::RadioButton("Classic", &e, 0);
                   ImGui::SameLine();
                   ImGui::RadioButton("Drak", &e, 1);
                   ImGui::SameLine();
                   ImGui::RadioButton("Light", &e, 2);
                   switch (e) {
                   case 0:
                   ImGui::StyleColorsClassic();
                   break;
                   case 1:
                   ImGui::StyleColorsDark();
                   break;
                   case 2:
                   ImGui::StyleColorsLight();
                   break;
        }				 
                ImGui::Spacing();
                ImGui::EndGroupPanel();
                ImGui::BeginGroupPanel("Additional", ImVec2(0.0f, 0.0f));
                ImGui::Checkbox("Show Icon Minimap", &Config.Visual.MaphackIcon);
				ImGui::Checkbox("Show HealthBar", &Config.Visual.HealthBar);
                ImGui::Text("Drone View:");
                ImGui::SliderFloat("##DroneView", &SetFieldOfView, 0, 30, "%.1f");
                ImGui::Spacing();
                ImGui::EndGroupPanel();
											
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Helper Menu")) {
				show_another_esp = false;
				show_another_kontol = false;
				

                ImGui::BeginGroupPanel("Auto Aim", ImVec2(0.0f, 0.0f));

                ImGui::BeginGroupPanel("Skills", ImVec2(0.0f, 0.0f));
				
                ImGui::Checkbox("Skill 1", &Aim.Helper.Skills.Skill1);
                ImGui::Checkbox("Skill 2", &Aim.Helper.Skills.Skill2);
                ImGui::Checkbox("Skill 3", &Aim.Helper.Skills.Skill3);
                ImGui::Checkbox("Skill 4", &Aim.Helper.Skills.Skill4);
                ImGui::Spacing();
                ImGui::EndGroupPanel();

                ImGui::SameLine();

                ImGui::BeginGroupPanel("Other", ImVec2(0.0f, 0.0f));
                ImGui::Checkbox("Basic Attack", &Aim.Helper.Skills.Basic);
                ImGui::Checkbox("Spell", &Aim.Helper.Skills.Spell);
                 ImGui::Spacing();
                ImGui::EndGroupPanel();

                ImGui::BeginGroupPanel("Priority", ImVec2(0.0f, 0.0f));
                ImGui::Text("Target Priority:");
                ImGui::RadioButton("Closest Distance", &Aim.Helper.Priority.Target, 0);
                ImGui::RadioButton("Lowest HP", &Aim.Helper.Priority.Target, 1);
                ImGui::RadioButton("Lowest HP Percentage", &Aim.Helper.Priority.Target, 2);
                ImGui::Text("Range Auto Aim:");
                ImGui::SliderFloat("##RangeFOV", &RangeFOV, 0, 150, "%.1fm");
                ImGui::Spacing();
                ImGui::EndGroupPanel();

                ImGui::SameLine();
				
                ImGui::Spacing();
                ImGui::EndGroupPanel();

                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Other Menu")) {
				show_another_esp = true;
				show_another_kontol = true;
                
				ImGui::BeginGroupPanel("Combo Hero", ImVec2(0.0f, 0.0f));
				ImGui::Checkbox("Manual Take Sword Ling (Crash)", &Aim.Helper.Priority.AutoTakeSword);
				ImGui::Checkbox("Automatic Take Sword Ling (Crash)", &Aim.Helper.AutoRetribution.Ling);
				ImGui::Checkbox("Xavier 1+2", &Aim.Helper.AutoCombo.Xavier);
				ImGui::Checkbox("Xavier 2+1", &Aim.Helper.AutoCombo.Xavier2);
				ImGui::Checkbox("Xavier 1+3", &Aim.Helper.AutoCombo.Xavier4);
				ImGui::Checkbox("Xavier 2+3", &Aim.Helper.AutoCombo.Xavier3);
				ImGui::Checkbox("Gusion 2+1+3+1+2", &Aim.Helper.AutoCombo.Gusion);
				ImGui::Checkbox("Gusion 1+2+3+1+2", &Aim.Helper.AutoCombo.Gusion2);
				ImGui::Checkbox("Chou Ulti+Fliker", &Aim.Helper.MoreFeature.Chou2);
				ImGui::Checkbox("Harith (Wrong)", &Aim.Helper.AutoCombo.Harith);
		        ImGui::Spacing();
                ImGui::EndGroupPanel();
				
				ImGui::SameLine();
                ImGui::BeginGroupPanel("Ultimate", ImVec2(0.0f, 0.0f));
				ImGui::Checkbox("Balmond", &Aim.Helper.AutoUltimate.Balmond);
				ImGui::Checkbox("Balmond V2", &Aim.Helper.Skills.Balmond);
				ImGui::Checkbox("Xavier", &Aim.Helper.AutoUltimate.Xavier);
				ImGui::Checkbox("Layla", &Aim.Helper.AutoUltimate.Layla);
				ImGui::Checkbox("Beatrix", &Aim.Helper.AutoUltimate.Beatrix);
				ImGui::Checkbox("Moskov", &Aim.Helper.AutoUltimate.Moskov);
				ImGui::Checkbox("Nana", &Aim.Helper.AutoUltimate.Nana);
				ImGui::Checkbox("Granger", &Aim.Helper.AutoUltimate.Granger);
				ImGui::Checkbox("Martis (Test)", &Aim.Helper.AutoUltimate.Martis);
				ImGui::Checkbox("Martis (Test V2)", &Aim.Helper.Skills.Martis);
			
				ImGui::Spacing();
                ImGui::EndGroupPanel();
				
				ImGui::SameLine();
				
				ImGui::BeginGroupPanel("Auto Retributtion", ImVec2(0.0f, 0.0f));
				ImGui::Checkbox("red", &Aim.Helper.AutoRetribution.Buff1);
				ImGui::Checkbox("Blue", &Aim.Helper.AutoRetribution.Buff2);
				ImGui::Checkbox("Lord", &Aim.Helper.AutoRetribution.Lord);
				ImGui::Checkbox("Turtle", &Aim.Helper.AutoRetribution.Turtle);
				ImGui::Checkbox("Crab", &Aim.Helper.AutoRetribution.Crab);
				ImGui::Checkbox("Litho", &Aim.Helper.AutoRetribution.Litho);
				ImGui::Checkbox("Scaled", &Aim.Helper.AutoRetribution.Scaled);
			    ImGui::Checkbox("Rockursa", &Aim.Helper.AutoRetribution.Rockursa);
				ImGui::Spacing();
                ImGui::EndGroupPanel();
				ImGui::BeginGroupPanel("Tap Tap", ImVec2(0.0f, 0.0f));
				ImGui::Checkbox("Pharsa", &Aim.Helper.MoreFeature.Pharsa);
				ImGui::SameLine();
				ImGui::BeginGroupPanel("Target Hp Enemy", ImVec2(0.0f, 0.0f));
				ImGui::SliderFloat("##Target Hp Enemy", &TargetHP, 0, 3000, "%.1f");
				ImGui::BeginGroupPanel("Distance", ImVec2(0.0f, 0.0f));
				ImGui::SliderFloat("##Distance", &TargetDistance, 0, 20, "%.1f");
				ImGui::BeginGroupPanel("Health Hero", ImVec2(0.0f, 0.0f));
				ImGui::SliderFloat("##HealthHero", &HealthHero, 0, 5000, "%.0f");
				ImGui::Spacing();
                ImGui::EndGroupPanel();
				
				ImGui::Spacing();
                ImGui::EndGroupPanel();
				
				ImGui::Spacing();
                ImGui::EndGroupPanel();
				
				
				
				
                

                ImGui::EndTabItem();
			}
                if (show_another_kontol) {
				ImGui::SetNextWindowSize(ImVec2((float) glWidth * 0.30f, (float) glHeight * 0.30f),ImGuiCond_Once);
        ImGui::Begin("About Eren Modz",
                     &show_another_kontol);
			    ImGui::BeginGroupPanel("About", ImVec2(0.0f, 0.0f));
			    ImGui::Text("DEVELOPER : @alfmodzdev2");
			    ImGui::Text("COPYRIGHT : BY EREN MODZ");
			    ImGui::Text("TELEGRAM : EREN MODZ");
			    ImGui::Text("CONTACT : @alfmodzdev2");
			    ImGui::Text("DEVELOPER FROM : INDONESIA");
			    ImGui::Text("GAME VERSION : GLOBAL");
			    ImGui::Text("BYPASS : STRONG+");
			    ImGui::Text("UI : SMOOTH");
				ImGui::Text("STATUS : SAFE");
				ImGui::Text("DEVICE : 100");
				ImGui::Text("KEY : jRrTdWnvpahyUKqP");
				ImGui::Text("NOTE : JIKA MENGGUNAKAN MOD INI BERMAIN LAH DENGAN BIJAK ^_^");
				ImGui::Spacing();
                ImGui::EndGroupPanel();
                
                ImGui::EndTabItem();
			}

                
            
            
			ImGui::EndTabItem();
			}
					    if (show_another_esp) {
	    ImGui::SetNextWindowSize(ImVec2((float) glWidth * 0.30f, (float) glHeight * 0.30f),ImGuiCond_Once);
        ImGui::Begin("Room Info",
                     &show_another_esp);
                RoomInfoList();
                ImGui::TextColored(ImVec4(0.0f, 0.8f, 1.0f, 1.0f), "Team");
                if (ImGui::BeginTable("##Team", 6, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
                    ImGui::TableSetupColumn("Name", 0, 150);
                    ImGui::TableSetupColumn("User ID", 0, 160);
                    ImGui::TableSetupColumn("Squad", 0, 190);
                    ImGui::TableSetupColumn("Rank", 0, 180);
                    ImGui::TableSetupColumn("Hero", 0, 130);
                    ImGui::TableSetupColumn("Spell", 0, 120);
                    ImGui::TableHeadersRow();
                    for (int row = 0; row < 5; row++) {
                        ImGui::TableNextRow();
                        for (int column = 0; column < 6; column++) {
                            ImGui::TableSetColumnIndex(column);
                            char buf[32];
                            if (column == 0) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Name.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 1) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].UserID.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 2) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Squad.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 3) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Rank.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 4) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Hero.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 5) {
                                sprintf(buf, "%s", RoomInfo.PlayerB[row].Spell.c_str());
                                ImGui::TextUnformatted(buf);
                            }
                        }
                    }
                    ImGui::EndTable();
                }
                ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "Enemy");
                if (ImGui::BeginTable("##Enemy", 6, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner)) {
                    ImGui::TableSetupColumn("Name", 0, 150);
                    ImGui::TableSetupColumn("User ID", 0, 160);
                    ImGui::TableSetupColumn("Squad", 0, 190);
                    ImGui::TableSetupColumn("Rank", 0, 180);
                    ImGui::TableSetupColumn("Hero", 0, 130);
                    ImGui::TableSetupColumn("Spell", 0, 120);
                    ImGui::TableHeadersRow();
                    for (int row = 0; row < 5; row++) {
                        ImGui::TableNextRow();
                        for (int column = 0; column < 6; column++) {
                            ImGui::TableSetColumnIndex(column);
                            char buf[32];
                            if (column == 0) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Name.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 1) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].UserID.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 2) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Squad.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 3) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Rank.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 4) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Hero.c_str());
                                ImGui::TextUnformatted(buf);
                            } else if (column == 5) {
                                sprintf(buf, "%s", RoomInfo.PlayerR[row].Spell.c_str());
                                ImGui::TextUnformatted(buf);
                            }
                        }
                    }
                    ImGui::EndTable();
                }
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }

    }

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    if (clearMousePos) {
        io->MousePos = ImVec2(-1, -1);
        clearMousePos = false;
    }
    return orig_eglSwapBuffers(dpy, surface);
}
void *main_thread(void *) {
    while (!m_IL2CPP) {
        m_IL2CPP = Tools::GetBaseAddress(m_IL2CPPLIB);
        sleep(1);
    }

while (!m_ANDROID) {
  m_ANDROID = dlopen_ex("libandroid.so", RTLD_NOW);
  sleep(1);
 }
 
while (!m_INPUT) {
  m_INPUT = dlopen_ex("libinput.so", RTLD_NOW);
  sleep(1);
 }


while (!m_EGL) {
        m_EGL = dlopen_ex("libEGL.so", RTLD_NOW);
        sleep(1);
    }

    Il2CppAttach(m_IL2CPPLIB);
    sleep(5);

Tools::Hook((void *) dlsym_ex(m_INPUT, "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE"), (void *) myInput, (void **) &origInput);
Tools::Hook((void *) dlsym_ex(m_ANDROID, "ANativeWindow_getWidth"), (void *) _ANativeWindow_getWidth, (void **) &orig_ANativeWindow_getWidth);
Tools::Hook((void *) dlsym_ex(m_ANDROID, "ANativeWindow_getHeight"), (void *) _ANativeWindow_getHeight, (void **) &orig_ANativeWindow_getHeight);
Tools::Hook((void *) dlsym_ex(m_EGL, "eglSwapBuffers"), (void *) _eglSwapBuffers, (void **) &orig_eglSwapBuffers);
Tools::Hook((void *) BattleManager_Update, (void *) UpdateMapHack, (void **) &oUpdateMapHack);
Tools::Hook((void *) ShowUnitAIComp_TryUseSkill, (void *) TryUseSkill, (void **) &orig_TryUseSkill);
Tools::Hook((void *) ShowUnitAIComp_Update, (void *) UpdateRetribution, (void **) &orig_UpdateRetribution);

        
    pthread_t t;
    return 0;
}

__attribute__((constructor))
void lib_main() {
    pthread_t ptid;
    pthread_create(&ptid, NULL, main_thread, NULL);
}

JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
	jvm = vm;
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    return JNI_VERSION_1_6;
}
