using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AnimationControl : MonoBehaviour
{
    public GameObject tracker;
    public GameObject target;

    public float timmer;
    public float time;

    public double timeStepSpeed;
    public int curStep;
    public ArrayList ts;
    void Start()
    {
        curStep = 0;
        timmer = 0;
        time = 0.02f;
        ts = GameObject.Find("Main Camera").GetComponent<readFile>().timeSteps;
    }

    // Update is called once per frame
    void Update()
    {
        
        if (timmer > 0)
            timmer -= Time.deltaTime;
        if (timmer <= 0)
        {
            run();
            timmer = time;
        }
    }

    void run()
    {
        if (curStep<=ts.Count-1)
        {
            target.GetComponent<Animation>().Move(((TimeStep)ts[curStep]).target_x, ((TimeStep)ts[curStep]).target_y, curStep);
            tracker.GetComponent<Animation>().Move(((TimeStep)ts[curStep]).tracker_x, ((TimeStep)ts[curStep]).tracker_y, curStep);
            curStep++;
        }
        
        
    }
}
