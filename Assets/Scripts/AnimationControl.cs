﻿using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using UnityEngine;
using UnityEngine.SceneManagement;
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
    public ArrayList forageTimeSteps;
    Boolean toRun = false;
    public Boolean toPlay = true;
    public GameObject distanceGraph;
    public GameObject switchGraph;

    public GameObject tiGraph;
    public agent[] agents;
    public ArrayList agentList;
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
    public GameObject agent0;
    Scene scene;
    agentTI[] grids;
    public void AnimationStart(string positionFile, string IRangeFile, string TRangeFile, string IstepFile, string TstepFile)
    {
        //isComplete = false;
        grids = gridContent.transform.GetComponentsInChildren<agentTI>();
        ReadTimestep(positionFile);
        ReadAgentTI(IRangeFile, TRangeFile, IstepFile, TstepFile);
        DrawAndRun();
        tsSlider.GetComponent<Slider>().maxValue = timeSteps.Count - 1;
        //tsSlider.GetComponent<Slider>().minValue = 1;
        tsSlider.transform.GetChild(2).GetChild(0).GetChild(0).GetComponent<Text>().text = "" + curStep;
    }
    public GameObject gridContent;
    public GameObject gridPrefab;
    public List<GameObject> gridAgent;

    List<Sprite> LoadSprite;
    int forageStepNum;
    int forageAgentNum;
    int step_num;
    ArrayList stepNest_foodin;
    ArrayList stepNest_numactors;
    public void ForageAnimationStart(string positionFile,string agent_num, string step_num, List<Sprite> loadSprite, ArrayList stepNest_foodin,
    ArrayList stepNest_numactors)
    {
        this.step_num = int.Parse(step_num);
        this.stepNest_foodin = stepNest_foodin;
        this.stepNest_numactors = stepNest_numactors;
        LoadSprite = loadSprite;
        gridAgent = new List<GameObject>();
        Debug.Log("run." + positionFile);
        forageAgentNum = int.Parse(agent_num);
        forageStepNum = int.Parse(step_num);
        for (int i = 0; i< forageAgentNum; i++) {
            GameObject curagent = Instantiate(gridPrefab);
            curagent.transform.parent = gridContent.transform;
            gridAgent.Add(curagent);
        }
        
        distanceGraph.GetComponent<Window_ForageGraph>().createG_foodin(stepNest_foodin);
        switchGraph.GetComponent<Window_ForageGraph>().createG_numactors(stepNest_numactors);
        tsSlider.GetComponent<Slider>().maxValue = int.Parse(step_num) - 1;
        //tsSlider.GetComponent<Slider>().minValue = 1;

        tsSlider.transform.GetChild(2).GetChild(0).GetChild(0).GetComponent<Text>().text = "" + curStep;
        toRun = true;
        toPlay = true;
    }

    public GameObject loading;
    void changeSprite()
    {
        if(loading.active == true)
        {
            loading.SetActive(false);
        }
        
    
        for (int i = 0; i < forageAgentNum; i++)
        {
            gridAgent[i].GetComponent<Image>().sprite = (Sprite)LoadSprite[curStep*forageAgentNum+i];
        }
    }

    private void ReadAgentTI(string irangeFile, string trangeFile, string istepFile, string tstepFile)
    {
        capacity = 20;
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
        for (int v = 0; v < capacity; v++)
        {
            if ((line = irangeReader.ReadLine()) != null)          //Read from top to bottom, then put variable name as key, value as value to a hashtable.
            {
                string[] ts = Regex.Split(line, "\\s+", RegexOptions.IgnoreCase);
                //Debug.Log(INmax.Length);

                INmax[v] = float.Parse(ts[6]);
                IEmax[v] = float.Parse(ts[10]);
                ISmax[v] = float.Parse(ts[14]);
                IWmax[v] = float.Parse(ts[18]);
            }
        }
        irangeReader.Close();

        // read trange
        for (int v = 0; v < capacity; v++)
        {
            if ((line = trangeReader.ReadLine()) != null)          //Read from top to bottom, then put variable name as key, value as value to a hashtable.
            {
                string[] ts = Regex.Split(line, "\\s+", RegexOptions.IgnoreCase);
                TNmax[v] = float.Parse(ts[6]);
                TEmax[v] = float.Parse(ts[10]);
                TSmax[v] = float.Parse(ts[14]);
                TWmax[v] = float.Parse(ts[18]);
            }
        }
        trangeReader.Close();

        // read istep

        agentList = new ArrayList();
        for (int v = 0; v < capacity; v++)
        {
            agents = new agent[timeSteps.Count];
            agentList.Add(agents);
        }
        

        StreamReader istepReader = new StreamReader(istepFile, Encoding.Default);
        StreamReader tstepReader = new StreamReader(tstepFile, Encoding.Default);

        int i = 0;
        while ((line = istepReader.ReadLine()) != null)
        {
            string line2 = tstepReader.ReadLine();
            string[] ts1 = Regex.Split(line, "\\s+", RegexOptions.IgnoreCase);
            string[] ts2 = Regex.Split(line2, "\\s+", RegexOptions.IgnoreCase);

            //Debug.Log("agents1 " + agents.Length + " ts1 " + ts1.Length + " ts2" + ts2.Length);
            for (int v = 0; v < capacity; v++)
            {
                ((agent[])agentList[v])[i] = new agent(v, float.Parse(ts1[6+v*10])
                                        , float.Parse(ts1[12 + v * 10])
                                        , float.Parse(ts1[10 + v * 10])
                                        , float.Parse(ts1[8 + v * 10])
                                        , float.Parse(ts2[6 + v * 10])
                                        , float.Parse(ts2[12 + v * 10])
                                        , float.Parse(ts2[10 + v * 10])
                                        , float.Parse(ts2[8 + v * 10])
                                        , INmax[v]
                                        , IWmax[v]
                                        , ISmax[v]
                                        , IEmax[v]
                                        , TNmax[v]
                                        , TWmax[v]
                                        , TSmax[v]
                                        , TEmax[v]);
            }
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

    float timeForage;
    void Start()
    {
        curStep = 0;
        timmer = 0;
        time = 0.02f;
        timeForage = 1f;
        scene = SceneManager.GetActiveScene();


            //ts = GameObject.Find("Main Camera").GetComponent<readFile>().timeSteps;
        }

    // Update is called once per frame
    void Update()
    {
        Scene scene = SceneManager.GetActiveScene();
        if (scene.name.Equals("SetParamForage"))
        {
            if (toRun == true && toPlay == true)
            {
                if (timmer > 0)
                    timmer -= Time.deltaTime;
                if (timmer <= 0)
                {


                    ForageRun();

                    timmer = timeForage;
                }
            }
        }
        else
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
    }
    void ForageRun()
    {
        //Debug.Log(forageTimeSteps.Count);
        if (curStep <= forageStepNum - 1)
        {
            tsSlider.GetComponent<Slider>().value = curStep;
            tsSlider.transform.GetChild(2).GetChild(0).GetChild(0).GetComponent<Text>().text = "" + curStep;
            distanceGraph.GetComponent<Window_ForageGraph>().setcurrentDot(curStep);
            switchGraph.GetComponent<Window_ForageGraph>().setcurrentDot(curStep);
            changeSprite();
            curStep++;
        }
        else
        {
            tsSlider.transform.parent.GetComponent<TimeStepControl>().toStop();
        }
    }


    void run()
    {
        //Debug.Log(timeSteps.Count);
        if (curStep<=timeSteps.Count-1)
        {
            tsSlider.GetComponent<Slider>().value = curStep;
            tsSlider.transform.GetChild(2).GetChild(0).GetChild(0).GetComponent<Text>().text = ""+curStep;
            target.GetComponent<Animation>().Move(((TimeStep)timeSteps[curStep ]).target_x, ((TimeStep)timeSteps[curStep ]).target_y, curStep);
            tracker.GetComponent<Animation>().Move(((TimeStep)timeSteps[curStep ]).tracker_x, ((TimeStep)timeSteps[curStep ]).tracker_y, curStep);
            distanceGraph.GetComponent<Window_Graph>().setcurrentDot(curStep);
            switchGraph.GetComponent<Window_Graph>().setcurrentDot(curStep);
            int v = 0;
            foreach (agentTI ati in grids)
            {
                ati.Set(((agent[])agentList[v])[curStep]);
                v++;
            }
            curStep++;
        }
        else
        {
            tsSlider.transform.parent.GetComponent<TimeStepControl>().toStop();
        }
    }



    public void runOneShot()
    {
        Scene scene = SceneManager.GetActiveScene();
        if (scene.name.Equals("SetParamForage"))
        {
            if (curStep <= step_num - 1)
            {
                for (int i = 0; i < forageAgentNum; i++)
                {
                    gridAgent[i].GetComponent<Image>().sprite = (Sprite)LoadSprite[curStep * forageAgentNum + i];
                }
                distanceGraph.GetComponent<Window_ForageGraph>().setcurrentDot(curStep);
                switchGraph.GetComponent<Window_ForageGraph>().setcurrentDot(curStep);
            }
        }
        else if (scene.name.Equals("SetParamTracker"))
        {
            if (curStep <= timeSteps.Count - 1)
            {
                Debug.Log("oneshot");
                target.GetComponent<Animation>().Move(((TimeStep)timeSteps[curStep]).target_x, ((TimeStep)timeSteps[curStep]).target_y, curStep);
                tracker.GetComponent<Animation>().Move(((TimeStep)timeSteps[curStep]).tracker_x, ((TimeStep)timeSteps[curStep]).tracker_y, curStep);
                distanceGraph.GetComponent<Window_Graph>().setcurrentDot(curStep);
                switchGraph.GetComponent<Window_Graph>().setcurrentDot(curStep);

                int v = 0;
                foreach (agentTI ati in grids)
                {
                    ati.Set(((agent[])agentList[v])[curStep]);
                    v++;
                }
            }
        }
    }
}

