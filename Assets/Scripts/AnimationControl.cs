using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using UnityEngine;
using UnityEngine.UI;

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
    public Boolean toPlay = true;
    public GameObject distanceGraph;
    public GameObject switchGraph;

    public GameObject tiGraph;
    public agent[] agents;
    public GameObject tsSlider;
    public GameObject GameSpeedSlider;
    public float[] INmax;
    public float[] IWmax;
    public float[] ISmax;
    public float[] IEmax;

    public float[] TNmax;
    public float[] TWmax;
    public float[] TSmax;
    public float[] TEmax;

    public int capacity ;
    public bool isComplete;
    public void AnimationStart(string positionFile, string IRangeFile, string TRangeFile, string IstepFile, string TstepFile)
    {
        //isComplete = false;
        ReadTimestep(positionFile);
        ReadAgentTI(IRangeFile, TRangeFile, IstepFile, TstepFile);
        
        DrawAndRun();
        tsSlider.GetComponent<Slider>().maxValue = timeSteps.Count - 1;
        //tsSlider.GetComponent<Slider>().minValue = 1;

        tsSlider.transform.GetChild(2).GetChild(0).GetChild(0).GetComponent<Text>().text = "" + curStep;
        

    }

    private void ReadAgentTI(string irangeFile, string trangeFile, string istepFile, string tstepFile)
    {
        capacity = 1;
        INmax = new float[capacity];
        IWmax = new float[capacity];
        ISmax = new float[capacity];
        IEmax = new float[capacity];
        TNmax = new float[capacity];
        TWmax = new float[capacity];
        TSmax = new float[capacity];
        TEmax = new float[capacity];
        // read irange
        StreamReader irangeReader = new StreamReader(irangeFile, Encoding.Default);
        StreamReader trangeReader = new StreamReader(trangeFile, Encoding.Default);

        string line;
        int count = 0;
        int count2 = 0;
        if ((line = irangeReader.ReadLine()) != null)          //Read from top to bottom, then put variable name as key, value as value to a hashtable.
        {
            string[] ts = Regex.Split(line, "\\s+", RegexOptions.IgnoreCase);
            //Debug.Log(INmax.Length);
            INmax[count] = float.Parse(ts[6]);
            IEmax[count] = float.Parse(ts[10]);
            ISmax[count] = float.Parse(ts[14]);
            IWmax[count] = float.Parse(ts[18]);
            count++;
        }
        irangeReader.Close();

        // read trange
        if ((line = trangeReader.ReadLine()) != null)          //Read from top to bottom, then put variable name as key, value as value to a hashtable.
        {
            string[] ts = Regex.Split(line, "\\s+", RegexOptions.IgnoreCase);
            TNmax[count2] = float.Parse(ts[6]);
            TEmax[count2] = float.Parse(ts[10]);
            TSmax[count2] = float.Parse(ts[14]);
            TWmax[count2] = float.Parse(ts[18]);
            count2++;
        }
        trangeReader.Close();

        // read istep
        agents = new agent[timeSteps.Count];
        StreamReader istepReader = new StreamReader(istepFile, Encoding.Default);
        StreamReader tstepReader = new StreamReader(tstepFile, Encoding.Default);

        int i = 0;
        while ((line = istepReader.ReadLine()) != null)
        {
            string line2 = tstepReader.ReadLine();
            string[] ts1 = Regex.Split(line, "\\s+", RegexOptions.IgnoreCase);
            string[] ts2 = Regex.Split(line2, "\\s+", RegexOptions.IgnoreCase);

            //Debug.Log("agents1 " + agents.Length + " ts1 " + ts1.Length + " ts2" + ts2.Length);
            agents[i] = new agent(0, float.Parse(ts1[6])
                                    , float.Parse(ts1[12])
                                    , float.Parse(ts1[10])
                                    , float.Parse(ts1[8])
                                    , float.Parse(ts2[6])
                                    , float.Parse(ts2[12])
                                    , float.Parse(ts2[10])
                                    , float.Parse(ts2[8])
                                    , INmax[0]
                                    , IWmax[0]
                                    , ISmax[0]
                                    , IEmax[0]
                                    , TNmax[0]
                                    , TWmax[0]
                                    , TSmax[0]
                                    , TEmax[0]);
            i++;
            
        }
            istepReader.Close();
        // read tstep
       

        tstepReader.Close();
        
    }

    void DrawAndRun()
    {
        target.GetComponent<Animation>().draw();
        tracker.GetComponent<Animation>().draw();
        distanceGraph.GetComponent<Window_Graph>().createG(timeSteps);
        switchGraph.GetComponent<Window_Graph>().createG_switch(timeSteps);
       
        
        toRun = true;
        //runOneShot();
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
        sr.ReadLine();
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

    void BuildTimestep(string line)
    {
        string[] ts = Regex.Split(line, "\\s+", RegexOptions.IgnoreCase);
        int step = 3;
        TimeStep t1 = new TimeStep(int.Parse(ts[2]), step * float.Parse(ts[4]), step * float.Parse(ts[5]), step * float.Parse(ts[7]), step * float.Parse(ts[8]), float.Parse(ts[10]), int.Parse(ts[31]));
        timeSteps.Add(t1);
        //Debug.Log(t1.idle);
        //Debug.Log(param[0] + " " + param[1]);
    }

    void Start()
    {
        curStep = 10;
        timmer = 0;
        time = 0.02f;
        

        //ts = GameObject.Find("Main Camera").GetComponent<readFile>().timeSteps;
    }

    // Update is called once per frame
    void Update()
    {
        if (toRun == true && toPlay == true)
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
        Debug.Log(timeSteps.Count);
        if (curStep<=timeSteps.Count-1)
        {
            tsSlider.GetComponent<Slider>().value = curStep;
            tsSlider.transform.GetChild(2).GetChild(0).GetChild(0).GetComponent<Text>().text = ""+curStep;
            target.GetComponent<Animation>().Move(((TimeStep)timeSteps[curStep ]).target_x, ((TimeStep)timeSteps[curStep ]).target_y, curStep);
            tracker.GetComponent<Animation>().Move(((TimeStep)timeSteps[curStep ]).tracker_x, ((TimeStep)timeSteps[curStep ]).tracker_y, curStep);
            distanceGraph.GetComponent<Window_Graph>().setcurrentDot(curStep);
            switchGraph.GetComponent<Window_Graph>().setcurrentDot(curStep);
            
            tiGraph.GetComponent<agentTI>().Set(agents[curStep]);
            curStep++;
        }
    }
    public void runOneShot()
    {
        //Debug.Log(timeSteps.Count);
        if (curStep <= timeSteps.Count - 1)
        {
            Debug.Log("oneshot");
            target.GetComponent<Animation>().Move(((TimeStep)timeSteps[curStep]).target_x, ((TimeStep)timeSteps[curStep]).target_y, curStep);
            tracker.GetComponent<Animation>().Move(((TimeStep)timeSteps[curStep]).tracker_x, ((TimeStep)timeSteps[curStep]).tracker_y, curStep);
            distanceGraph.GetComponent<Window_Graph>().setcurrentDot(curStep);
            switchGraph.GetComponent<Window_Graph>().setcurrentDot(curStep);

            tiGraph.GetComponent<agentTI>().Set(agents[curStep]);
        }
    }
}
