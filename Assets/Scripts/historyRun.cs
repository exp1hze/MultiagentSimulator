using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class historyRun : MonoBehaviour
{
    
    public GameObject runButton;
    // Start is called before the first frame update
    void Start()
    {
        GameObject history = GameObject.Find("runPath");
        if (history.GetComponent<runParam>().history == true)
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
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
