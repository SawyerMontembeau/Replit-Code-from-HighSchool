using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerCasting : MonoBehaviour
{

    //static keyword allows differnt scripts to access the static variable or method
    //static varibles Can't be seen in the unity inspector panel
    public static float distanceFromTarget;
    public static Vector3 point;
    public static Vector3 normal;
    public static GameObject killObject;
    public float toTarget;
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //Raycast being fired out every single frame so we know how far we are from objects
        //note how we are declaring this 'hit' variable locally inside Update
        RaycastHit hit;
        //tell the code that we want to fire out the raycast an have it return a number back to us that is the distance 
        //the direction we are going to face the raycast = transform.TransformDirection(Vector3.forward)
        if (Physics.Raycast(transform.position, transform.TransformDirection(Vector3.forward), out hit))
        {//This if statement returns true/false and sends info about what we hit to the variable hit
            Debug.Log(hit.collider.gameObject.name);
            killObject = hit.collider.gameObject;// this will be the gameobject we destroy
            toTarget = hit.distance;
            distanceFromTarget = hit.distance;
            point = hit.point;//this is the point in space on your raycast target that you want to instantiate the impact effect
            normal = hit.normal;//this is just the plane on the 3d impact effect GameObject cube that we want to project FROM
            //
        }
    }
}
