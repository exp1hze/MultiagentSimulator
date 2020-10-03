using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TimeStep : MonoBehaviour
{
    public int time;
    public float target_x;
    public float target_y;
    public float tracker_x;
    public float tracker_y;
    public TimeStep(int t, float tx, float ty, float trx, float ry)
    {
        time = t;
        target_x = tx;
        target_y=ty;
        tracker_x=trx;
        tracker_y=ry;
    }

    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
