using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TimeStep : MonoBehaviour
{
    public int time;
    public double target_x;
    public double target_y;
    public double tracker_x;
    public double tracker_y;
    public TimeStep(int t, double tx, double ty, double trx, double ry)
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
