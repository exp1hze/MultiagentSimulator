using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
public class runSelectedFile : MonoBehaviour
{
    public Text fileName;
    GameObject runPath;

    void Start()
    {
        runPath = GameObject.Find("runPath");
        GameObject.DontDestroyOnLoad(runPath);
    }
    // Update is called once per frame
    void Update()
    {
        
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
       
        //Scene animaScene = SceneManager.GetSceneByName("SetParamTracker");
        //animaScene.GetRootGameObjects("a);
        //manimationPanel.SetActive(true);
        //parameterPanel.SetActive(false);



    }

    public void delete()
    {

        string path= Application.dataPath + "/Tracker/Output/"+fileName.text;

        DirectoryInfo di = new DirectoryInfo(path);
        di.Delete(true);

        Destroy(gameObject);
    }
}
