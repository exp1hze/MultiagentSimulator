using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
public class runSelectedFile : MonoBehaviour
{
    public Text fileName;
    GameObject runPath;
    string filePath;
    void Start()
    {
        runPath = GameObject.Find("runPath");
        GameObject.DontDestroyOnLoad(runPath);
        
        Scene scene = SceneManager.GetActiveScene();
        if (scene.name.Equals("selectForageFiles"))
        {
            filePath = Application.dataPath + "/Forage/Output/";
        }
        else
        {
            filePath = Application.dataPath + "/Tracker/Output/";
        }
    }
    // Update is called once per frame
    void Update()
    {
        
    }
    public void runFile()
    {
        Scene scene = SceneManager.GetActiveScene();
        if (scene.name.Equals("selectForageFiles"))
        {
            runASelectedForageFile();
        }
        else
        {
            runASelectedFile();
        }
    }
    public void runASelectedFile()
    {
        GameObject canvas = GameObject.Find("Canvas");
        GameObject loading = canvas.transform.Find("loading").gameObject;
        loading.SetActive(true);
        string run_num = transform.GetChild(0).GetComponent<Text>().text;
        string[] split = run_num.Split('.');
        run_num = split[1];
        //Debug.Log(run_num);
        runPath.GetComponent<runParam>().positionFile = Application.dataPath + "/Tracker/Output/run." + run_num + "/run." + run_num + ".stepsummary";
        runPath.GetComponent<runParam>().IRangeFile = Application.dataPath + "/Tracker/Output/run." + run_num + "/run." + run_num + ".intensityranges";
        runPath.GetComponent<runParam>().TRangeFile = Application.dataPath + "/Tracker/Output/run." + run_num + "/run." + run_num + ".threshrange";
        runPath.GetComponent<runParam>().IstepFile = Application.dataPath + "/Tracker/Output/run." + run_num + "/run." + run_num + ".stepintensity";
        runPath.GetComponent<runParam>().TstepFile = Application.dataPath + "/Tracker/Output/run." + run_num + "/run." + run_num + ".stepthresh";
        runPath.GetComponent<runParam>().history = true;
        SceneManager.LoadScene("SetParamTracker");

    }

    ArrayList stepNest_foodin;
    ArrayList stepNest_numactors;
    public void ReadStepNest(string path)
    {
        stepNest_foodin = new ArrayList();
        stepNest_numactors = new ArrayList();
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        while ((line = sr.ReadLine()) != null)
        {
            BuildStepNest(line);
        }
        Debug.Log("-------------------complete--------------");
        sr.Close();
    }

    public void BuildStepNest(string line)
    {
        string[] param = Regex.Split(line, "\\s+", RegexOptions.IgnoreCase);
        stepNest_foodin.Add(param[3]);
        stepNest_numactors.Add(param[5]);
        Debug.Log("-----------------------reading" + param[3] + " " + param[5]);
    }
    string agent_num;
    string step_num;
    public void runASelectedForageFile()
    {
        GameObject canvas = GameObject.Find("Canvas");
        GameObject loading = canvas.transform.Find("loading").gameObject;
        loading.SetActive(true);
        string run_num = transform.GetChild(0).GetComponent<Text>().text;
        string[] split = run_num.Split('.');
        run_num = split[1];
        runPath.GetComponent<runParam>().history = true;
        
        ReadStepNest(Application.dataPath + "/Forage/Output/run." + run_num + "/run." + run_num + ".stepnest");
        ReadFromParams(Application.dataPath + "/Forage/Output/run." + run_num+"/run."+ run_num + ".params");
        LoadTexture2Sprite(run_num, agent_num, step_num);

        runPath.GetComponent<runParam>().positionFile = run_num.ToString();
        runPath.GetComponent<runParam>().agent_num = agent_num;
        runPath.GetComponent<runParam>().step_num = step_num;
        runPath.GetComponent<runParam>().stepNest_numactors = stepNest_numactors;
        runPath.GetComponent<runParam>().stepNest_foodin = stepNest_foodin;
        runPath.GetComponent<runParam>().loadSprite = loadsprite;
        SceneManager.LoadScene("SetParamForage");
    }

    public void ReadFromParams(string path)
    {
        StreamReader sr = new StreamReader(path, Encoding.Default);
        string line;
        while ((line = sr.ReadLine()) != null)          //Read from top to bottom, then put variable name as key, value as value to a hashtable.
        {
            string[] param = Regex.Split(line, "\\s+", RegexOptions.IgnoreCase);
            //Debug.Log(param[1]);
            if (param[1].Equals("Max_steps")){
                step_num = param[3];
                //Debug.Log(param[2] + "asdasdsas");
            } else if (param[1].Equals("Pop_size")) {
                agent_num = param[3];
                //Debug.Log(param[2] + "asdasdsas");

            } }
        sr.Close();
    }

    public List<Sprite> loadsprite;
    // read img to sprite
    private void LoadTexture2Sprite(string runNum, string AgentNum, string StepNum)
    {
        int agentNum = int.Parse(AgentNum);
        int stepNum = int.Parse(StepNum);


        loadsprite = new List<Sprite>();
        for (int i = 0; i < stepNum; i++)
        {
            for (int j = 0; j < agentNum; j++)
            {
                string imgPath = Application.dataPath + "/Forage/Output/run." + runNum + "/run." +
                    runNum + ".agent" + j + ".step" + i + ".memory.png";
                Texture2D t2d = new Texture2D(200, 200);
                t2d.LoadImage(getImageByte(imgPath));
                Sprite sprite = Sprite.Create(t2d, new Rect(0, 0, t2d.width, t2d.height), Vector2.zero);
                loadsprite.Add(sprite);
            }
        }

    }
    public static byte[] getImageByte(string imagePath)
    {
        FileStream files = new FileStream(imagePath, FileMode.Open);
        byte[] imgByte = new byte[files.Length];
        files.Read(imgByte, 0, imgByte.Length);
        files.Close();
        return imgByte;
    }

    public void delete()
    {

        string path= filePath+fileName.text;

        DirectoryInfo di = new DirectoryInfo(path);
        di.Delete(true);

        Destroy(gameObject);
    }
}
