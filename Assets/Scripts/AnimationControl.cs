using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using UnityEngine;

public class AnimationControl : MonoBehaviour
{
    public GameObject tracker;
    public GameObject target;

    public float timmer;
    public float time;

    public double timeStepSpeed;
    public int curStep;
    //public ArrayList ts;
    public ArrayList timeSteps;
    Boolean toRun = false;
    public GameObject distanceGraph;
    public GameObject switchGraph;
    

    public void AnimationStart(string path)
    {
        ReadTimestep(path);
        DrawAndRun();
    }

    void DrawAndRun()
    {
        target.GetComponent<Animation>().draw();
        tracker.GetComponent<Animation>().draw();
        distanceGraph.GetComponent<Window_Graph>().createG(timeSteps);
        switchGraph.GetComponent<Window_Graph>().createG_switch(timeSteps);
        
        toRun = true;
        //StartCoroutine(WaitAndRun());

    }

    //IEnumerator WaitAndRun()
    //{
    //    yield return new WaitForSeconds(0.2f);
    //    run();
    //}

    public void ReadTimestep(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        timeSteps = new ArrayList();
        string line;
        while ((line = sr.ReadLine()) != null)          //Read from top to bottom, then put variable name as key, value as value to a hashtable.
        {
            BuildTimestep(line);
        }
        //foreach (TimeStep t1 in timeSteps)
        //{
        //    Debug.Log(t1.time+" "+t1.target_x+" "+t1.target_y+" "+t1.tracker_x+" "+t1.tracker_y);
        //}
        //Debug.Log("Rerun : " + _params["Rerun"]);
        sr.Close();
    }

    public void BuildTimestep(string line)
    {
        string[] ts = Regex.Split(line, "\\s+", RegexOptions.IgnoreCase);
        int step = 3;
        Debug.Log(ts.Length);
        
        TimeStep t1 = new TimeStep(int.Parse(ts[2]), step * float.Parse(ts[4]), step * float.Parse(ts[5]), step * float.Parse(ts[7]), step * float.Parse(ts[8]), float.Parse(ts[10]), int.Parse(ts[31]));
        timeSteps.Add(t1);
        //Debug.Log(t1.idle);
        //Debug.Log(param[0] + " " + param[1]);
    }
    void Start()
    {
        curStep = 0;
        timmer = 0;
        time = 0.02f;
        //ts = GameObject.Find("Main Camera").GetComponent<readFile>().timeSteps;
    }

    // Update is called once per frame
    void Update()
    {
        if (toRun == true)
        {
            if (timmer > 0)
                timmer -= Time.deltaTime;
            if (timmer <= 0)
            {
                run();
                timmer = time;
            }
        }

    }

    void run()
    {
        
        //Debug.Log("runrun");
        if (curStep<=timeSteps.Count-1)
        {
            target.GetComponent<Animation>().Move(((TimeStep)timeSteps[curStep]).target_x, ((TimeStep)timeSteps[curStep]).target_y, curStep);
            tracker.GetComponent<Animation>().Move(((TimeStep)timeSteps[curStep]).tracker_x, ((TimeStep)timeSteps[curStep]).tracker_y, curStep);
            distanceGraph.GetComponent<Window_Graph>().setcurrentDot(curStep);
            switchGraph.GetComponent<Window_Graph>().setcurrentDot(curStep);
            curStep++;
        }
        
        
    }
}
