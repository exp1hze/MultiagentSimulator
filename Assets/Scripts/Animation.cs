using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Animation : MonoBehaviour
{
    public int currTimeStep;
    public float moveX;
    public float moveY;

    void Start()
    {
        
    }
    void Update()
    {
        
    }
    public bool Move(float x, float y,int cts)
    {
        currTimeStep = cts;
        moveX = x;moveY = y;
        if (moveX == transform.position.x&& moveY == transform.position.y)
        {
            return false;
        }

        float speed = 5;
        //transform.position = Vector2.MoveTowards(transform.position,new Vector2(moveX,moveY),speed*Time.deltaTime);
        
        transform.position = new Vector2(transform.parent.position.x+moveX, transform.parent.position.y + moveY);
        Debug.Log(x+" "+y);
        return true;
    }
}
