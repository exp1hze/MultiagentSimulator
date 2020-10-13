using geniikw.DataRenderer2D;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Animation : MonoBehaviour
{
    public GameObject line;
    public int currTimeStep;
    public float moveX;
    public float moveY;
    public ArrayList ts;
    public GameObject animationPanel;

    public void draw()
    {

        //ts = GameObject.Find("Main Camera").GetComponent<readFile>().timeSteps;
        ts = animationPanel.GetComponent<AnimationControl>().timeSteps;
        UILine draw = line.GetComponent<UILine>();
        while (draw.line.Count < ts.Count)
        {
            draw.line.Push();
        }
        for (int i = 0; i < ts.Count; i++)
        {
            if(line.gameObject.name == "TargetLine")
            {
                Vector2 pos = new Vector2(transform.parent.position.x + ((TimeStep)ts[i]).target_x, transform.parent.position.y + ((TimeStep)ts[i]).target_y);
                draw.line.EditPoint(i, pos, 0.5f);
            }
            else
            {
                Vector2 pos = new Vector2(transform.parent.position.x +((TimeStep)ts[i]).tracker_x, transform.parent.position.y + ((TimeStep)ts[i]).tracker_y);
                draw.line.EditPoint(i, pos, 0.5f);
            }
           
           
        }
    }
    void Update()
    {
        
    }
    public bool Move(float x, float y,int cts)
    {
        currTimeStep = cts;
        Debug.Log(cts);
        moveX = x;moveY = y;
        if (moveX == transform.position.x&& moveY == transform.position.y)
        {
            return false;
        }
        
        float scale = transform.parent.GetComponent<Drag>().scale;
        //transform.position = Vector2.MoveTowards(transform.position,new Vector2(moveX,moveY),speed*Time.deltaTime);
        float movex = transform.parent.position.x + moveX*scale;
        float movey = transform.parent.position.y + moveY *scale;
        transform.position = new Vector2(movex,movey);
        //Debug.Log(transform.position.x+" "+ transform.position.y);
        return true;
    }
}
