#pragma once

#define ARGB(a, r, g, b) 0 | a << 24 | r << 16 | g << 8 | b

#define WHITE               ARGB(255, 248, 248, 255)
#define RED                 ARGB(255, 0, 0, 255)
#define GREEN               ARGB(255, 000, 128, 000)
#define LIME                ARGB(255, 000, 255, 000)
#define BLUE                ARGB(255, 000, 000, 255)
#define BLACK               ARGB(255, 000, 000, 000)
#define PURPLE              ARGB(255, 125, 000, 255)
#define GREy                ARGB(255, 128, 128, 128)
#define yELLOW              ARGB(255, 0, 255, 255)
#define ORANGE              ARGB(255, 255, 125, 000)
#define DARK_GREEN          ARGB(255, 000, 100, 000)
#define PINK                ARGB(255, 255, 192, 203)
#define BROWN               ARGB(255, 210, 105, 30)
#define CyAN                ARGB(255, 000, 255, 255)


int isOutsideSafezone(Vector2 pos, Vector2 screen) {
    Vector2 mSafezoneTopLeft(screen.x * 0.04f, screen.y * 0.04f);
    Vector2 mSafezoneBottomRight(screen.x * 0.96f, screen.y * 0.96f);

    int result = 0;
    if (pos.y < mSafezoneTopLeft.y) {
        result |= 1;
    }
    if (pos.x > mSafezoneBottomRight.x) {
        result |= 2;
    }
    if (pos.y > mSafezoneBottomRight.y) {
        result |= 4;
    }
    if (pos.x < mSafezoneTopLeft.x) {
        result |= 8;
    }
    return result;
}

Vector2 pushToScreenBorder(Vector2 Pos, Vector2 screen, int borders, int offset) {
    int x = (int)Pos.x;
    int y = (int)Pos.y;
    if ((borders & 1) == 1) {
        y = 0 - offset;
    }
    if ((borders & 2) == 2) {
        x = (int)screen.x + offset;
    }
    if ((borders & 4) == 4) {
        y = (int)screen.y + offset;
    }
    if ((borders & 8) == 8) {
        x = 0 - offset;
    }
    return Vector2(x, y);
}


class ESP {
	private:
	JNIEnv *env;
	
	public:
	void drawLine(ImU32 col, float thickness, Vector2 start, Vector2 end) {
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(start.x, start.y), ImVec2(end.x, end.y), col, thickness);
	}
	void drawText(ImU32 col, const char *txt, Vector2 pos, float size) {
		ImGui::GetBackgroundDrawList()->AddText(NULL, size, ImVec2(pos.x, pos.y), col, txt);
	}
	void drawCircleFilled(ImU32 col, Vector2 pos, float radius) {
		ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(pos.x, pos.y), radius, col, 0);
	}
	void drawFilledRectangle(int x, int y, int w, int h, ImU32 col, float rounding) {
	ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), col, rounding);
}
void drawRectangle(int x, int y, int w, int h, ImU32 col, float rounding) {
	ImGui::GetBackgroundDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), col, rounding);
}

void drawBox(ImU32 color, float stroke, Rect rect) {
        Vector2 v1 = Vector2(rect.x, rect.y);
        Vector2 v2 = Vector2(rect.x + rect.width, rect.y);
        Vector2 v3 = Vector2(rect.x + rect.width, rect.y + rect.height);
        Vector2 v4 = Vector2(rect.x, rect.y + rect.height);

        drawLine(color, stroke, v1, v2); // Up
        drawLine(color, stroke, v2, v3); // Right
        drawLine(color, stroke, v3, v4); // Down
        drawLine(color, stroke, v4, v1); // Left
    }
	

void drawHp(Vector2 pos,float ch,float mh,int hpWidth){
	drawLine(ARGB(233, 000, 000, 000), 16, Vector2(pos.x,pos.y) ,Vector2(pos.x + hpWidth,pos.y));
	Vector2 start(pos.x + 2, pos.y);
	Vector2 end(pos.x - 2, pos.y);
	end.x += (ch * hpWidth) / mh;
	drawLine(RED, 16, start,end);
}

void drawHorizontalHealthBar(Vector2 vec, float curHp, float maxHp)
{
	vec -= Vector2(0.0f, 8.0f);
	drawBox(ARGB(255, 0, 0, 0), 6, Rect(vec.x, vec.y, 102, 8.0f));
	vec += Vector2(1.0f, 1.0f);
	ImU32 clr = GREEN;
	float args0 = (curHp * 100) / maxHp;
	if (curHp <= (maxHp * 0.6))
	{
		clr = yELLOW;
	}
	if (curHp < (maxHp * 0.3))
	{
		clr = RED;
	}
	drawBox(clr, 6, Rect(vec.x, vec.y, args0, 6.0f));
}

};
