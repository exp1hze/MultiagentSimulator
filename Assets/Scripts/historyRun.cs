using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class historyRun : MonoBehaviour
{
    
    public GameObject runButton;
    // Start is called before the first frame update
    void Start()
    {
        GameObject history = GameObject.Find("runPath");
        Scene scene = SceneManager.GetActiveScene();
        if (history.GetComponent<runParam>().history == true)
        {
            history.GetComponent<runParam>().history = false;
            if (scene.name.Equals("SetParamTracker"))
            {
                string positionFile = history.GetComponent<runParam>().positionFile;
                string IRangeFile = history.GetComponent<runParam>().IRangeFile;
                string TRangeFile = history.GetComponent<runParam>().TRangeFile;
                string IstepFile = history.GetComponent<runParam>().IstepFile;
                string TstepFile = history.GetComponent<runParam>().TstepFile;
                runButton.GetComponent<runButton>().animationPanel.SetActive(true);
                runButton.GetComponent<runButton>().parameterPanel.SetActive(false);
                runButton.GetComponent<runButton>().animationPanel.
                    GetComponent<AnimationControl>().AnimationStart(positionFile, IRangeFile, TRangeFile, IstepFile, TstepFile);
            }
            else
            {
                string positionFile = history.GetComponent<runParam>().positionFile;
                string agent_num = history.GetComponent<runParam>().agent_num;
                string step_num = history.GetComponent<runParam>().step_num;
                List<Sprite> loadSprite = history.GetComponent<runParam>().loadSprite;
                ArrayList stepNest_foodin = history.GetComponent<runParam>().stepNest_foodin;
                ArrayList stepNest_numactors = history.GetComponent<runParam>().stepNest_numactors;
                runButton.GetComponent<runButton>().animationPanel.SetActive(true);
                runButton.GetComponent<runButton>().parameterPanel.SetActive(false);
                runButton.GetComponent<runButton>().animationPanel.
                    GetComponent<AnimationControl>().ForageAnimationStart(positionFile, agent_num, step_num, loadSprite, stepNest_foodin,
                    stepNest_numactors);
            } 

        }
        


    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
