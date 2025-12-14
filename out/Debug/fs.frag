#version 330 core

out vec4 o; 

uniform vec2 r; //分辨率
uniform float it; //时间

// 立方体
float boxSDF(vec3 p, vec3 b) 
{
    vec3 d = abs(p) - b;
    return length(max(d, 0.0)) + min(max(d.x, max(d.y, d.z)), 0.0);
}
//边界
float wallSDF(vec3 p)
{
    return min(5-max(abs(p.x),abs(p.y)),5.6-length(p.xy));
}

float sceneSDF(vec3 p)
{
    vec3 modPos = mod(p, 2.0) - 1.0; // 创建重复的立方体阵列
    float box = boxSDF(modPos, vec3(0.25)); // 立方体大小
    return min(box,wallSDF(p));
}

void main()
{
    vec2 uv = (gl_FragCoord.xy / r) * 2. - 1.; 
    uv.x *= r.x / r.y; 

    vec3 ro = vec3(0.0, 0.0, -it*13-10*sin(it)); // 视点位置
    vec3 rd = normalize(vec3(uv*(1*sin(it)+2), -1.0)); // 射线方向

    float t = 0.0;
    bool hit = false;
    vec3 pos;
    vec3 normal;
    for (int i = 0; i < 128; i++) {
        pos = ro + rd * t;
        float d = sceneSDF(pos);
        if (d < 0.001) {
            hit = true;
            break;
        }
        t += d;
    }

    if (hit) {
        // 法线
        normal = normalize(vec3(
            sceneSDF(pos + vec3(0.001, 0.0, 0.0)) - sceneSDF(pos - vec3(0.001, 0.0, 0.0)),
            sceneSDF(pos + vec3(0.0, 0.001, 0.0)) - sceneSDF(pos - vec3(0.0, 0.001, 0.0)),
            sceneSDF(pos + vec3(0.0, 0.0, 0.001)) - sceneSDF(pos - vec3(0.0, 0.0, 0.001))
        ));

        // 光源
        vec3 lightPos1 = vec3(1.0, 1.0+ sin(it)*6, 1.0) +ro; // 动态光源位置
        vec3 lightPos2 = vec3(-1.0+ sin(it)*6, -1.0, 1.0)+ro ;
        
        // 计算光照
        vec3 lightDir1 = normalize(lightPos1 - pos);
        vec3 lightDir2 = normalize(lightPos2 - pos);
        float diffuse1 = max(dot(normal, lightDir1), 0.0);
        float diffuse2 = max(dot(normal, lightDir2), 0.0);
        float diffuse = diffuse1 + diffuse2;

        // 颜色
        vec3 color = vec3(1 * diffuse1, (sin(it*.84+.23)+1.)*.8 * diffuse2 , (sin(it*1.23+.79)+1.)*.8 * diffuse2)-vec3(0.5)*t*.05;

        o = vec4(color, 1.); // 输出最终颜色
    }
    else
    {
        o = vec4(vec3(0.0, 0.0, 0.0), 1.0);
    }
}
